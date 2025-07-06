# transfer_utils.py

import pandas as pd
from sqlalchemy import inspect
import logging
import yaml
from typing import Dict, List

logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)


def copy_all_tables(source_engine, target_engine):
    """
    Copy all tables and their data from source to target database.
    """
    inspector = inspect(source_engine)
    table_names = inspector.get_table_names()

    for table in table_names:
        try:
            logger.info(f"Copying table: {table}")
            df = pd.read_sql_table(table, source_engine)
            df.to_sql(table, target_engine, if_exists='replace', index=False)
        except Exception as e:
            logger.error(f"Failed to copy table {table}: {e}")


def copy_selected_from_config(config_path: str, source_engine, target_engine):
    """
    Copy selected tables/columns based on config file.
    Config format (YAML):
      tables:
        table1:
          - column1
          - column2
        table2:
          - "*"
    """
    with open(config_path, 'r') as f:
        config = yaml.safe_load(f)

    tables: Dict[str, List[str]] = config.get('tables', {})

    for table, columns in tables.items():
        try:
            logger.info(f"Copying selective data from table: {table}")
            if columns == ["*"]:
                df = pd.read_sql_table(table, source_engine)
            else:
                query = f"SELECT {', '.join(columns)} FROM {table}"
                df = pd.read_sql_query(query, source_engine)
            df.to_sql(table, target_engine, if_exists='replace', index=False)
        except Exception as e:
            logger.error(f"Error copying {table}: {e}")

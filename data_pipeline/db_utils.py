# db_utils.py
from sqlalchemy import create_engine
import logging

logger = logging.getLogger(__name__)

def get_engine(db_type, username, password, host, port, database):
    """
    Create a SQLAlchemy engine for different RDBMS types.
    """
    if db_type == "postgresql":
        uri = f"postgresql+psycopg2://{username}:{password}@{host}:{port}/{database}"
    elif db_type == "mysql":
        uri = f"mysql+pymysql://{username}:{password}@{host}:{port}/{database}"
    elif db_type in ("mssql", "sqlserver"):
        uri = f"mssql+pyodbc://{username}:{password}@{host}:{port}/{database}?driver=ODBC+Driver+17+for+SQL+Server"
    else:
        raise ValueError(f"Unsupported db_type: {db_type}")

    logger.info(f"Creating engine for {db_type}")
    engine = create_engine(uri)
    return engine

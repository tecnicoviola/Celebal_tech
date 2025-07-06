# export_utils.py
import os
import pandas as pd
from sqlalchemy import inspect

def export_tables(engine, output_dir):
    os.makedirs(output_dir, exist_ok=True)
    inspector = inspect(engine)
    tables = inspector.get_table_names()

    for table_name in tables:
        df = pd.read_sql_table(table_name, con=engine)

        # CSV
        df.to_csv(os.path.join(output_dir, f"{table_name}.csv"), index=False)

        # Parquet
        df.to_parquet(os.path.join(output_dir, f"{table_name}.parquet"), index=False)

        # Avro (optional: skip or implement if needed)
        # You can use `fastavro` if you want Avro export

        print(f"Exported {table_name}")

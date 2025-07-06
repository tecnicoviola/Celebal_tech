# main.py
import argparse
import logging
from db_utils import get_engine
from export_utils import export_tables

def run_export_mode(db_config, output_dir):
    engine = get_engine(**db_config)  # works now since keys match args
    export_tables(engine, output_dir)

if __name__ == "__main__":
    logging.basicConfig(level=logging.INFO)

    parser = argparse.ArgumentParser()
    parser.add_argument("--mode", choices=["export", "transfer_all", "transfer_selected"], required=True)
    parser.add_argument("--output_dir", help="Directory to store exported files")
    args = parser.parse_args()

    # ✅ Updated to use 'db_type' instead of 'type'
    db_config = {
        "db_type": "postgresql",                # use 'postgresql', 'mysql', or 'mssql'
        "username": "postgres",
        "password": "root@123",
        "host": "localhost",
        "port": 5432,
        "database": "postgres"
    }

    if args.mode == "export":
        run_export_mode(db_config, args.output_dir)

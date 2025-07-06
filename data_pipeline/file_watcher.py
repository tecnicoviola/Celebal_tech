# file_watcher.py

import time
from watchdog.observers import Observer
from watchdog.events import FileSystemEventHandler
import subprocess
import logging

logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

class TriggerHandler(FileSystemEventHandler):
    def on_created(self, event):
        if event.src_path.endswith('.trigger'):
            logger.info(f"Trigger file detected: {event.src_path}")
            subprocess.run(['python', 'main.py', '--mode', 'export', '--output_dir', './output'])


if __name__ == "__main__":
    path_to_watch = "./watch_dir"
    os.makedirs(path_to_watch, exist_ok=True)

    event_handler = TriggerHandler()
    observer = Observer()
    observer.schedule(event_handler, path=path_to_watch, recursive=False)

    logger.info("Watching for trigger files...")
    observer.start()

    try:
        while True:
            time.sleep(1)
    except KeyboardInterrupt:
        observer.stop()
    observer.join()
import os
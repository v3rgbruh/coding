import os
import pytest

from alembic import command
from alembic.config import Config
from sqlalchemy.dialects import sqlite
from sqlalchemy_utils import create_database, drop_database

BASE_DIR = os.path.join(os.path.dirname(os.path.dirname(os.path.dirname(__file__))), "2_task_api")
DB_NAME = "db-test.sqlite"
TEST_SQLALCHEMY_DB_URL = f"sqlite:///{DB_NAME}"


@pytest.fixture(scope="module")
def temp_db():
    os.system(command=f"cp db.sqlite {DB_NAME}")
    create_database(TEST_SQLALCHEMY_DB_URL, template=sqlite)
    alembic_cfg = Config(os.path.join(BASE_DIR, "alembic.ini"))
    command.upgrade(alembic_cfg, "head")

    try:
        yield TEST_SQLALCHEMY_DB_URL
    finally:
        drop_database(TEST_SQLALCHEMY_DB_URL)

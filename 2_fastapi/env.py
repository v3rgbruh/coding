from logging.config import fileConfig
from alembic import context
from models import products, categories, product_categories

config = context.config

section = config.config_ini_section
fileConfig(config.config_file_name)

target_metadata = [products.metadata, categories.metadata, product_categories.metadata]
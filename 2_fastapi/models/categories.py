from sqlalchemy import Column, Table, MetaData, Text, Integer

metadata = MetaData()

categories_t = Table(
    "categories",
    metadata,
    Column("id", Integer, primary_key=True, unique=True, nullable=False),
    Column("name", Text, nullable=False)
)

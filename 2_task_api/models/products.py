from sqlalchemy import Column, Table, MetaData, Text, Integer

metadata = MetaData()

products_t = Table(
    "products",
    metadata,
    Column("id", Integer, primary_key=True, unique=True, nullable=False),
    Column("name", Text, nullable=False)
)

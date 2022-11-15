from sqlalchemy import *
from .products import products_t
from .categories import categories_t

metadata = MetaData()


product_categories_t = Table(
    "product_categories",
    metadata,
    Column("product_id", Integer, ForeignKey(products_t.c.id), nullable=False),
    Column("category_id", Integer, ForeignKey(categories_t.c.id))
)

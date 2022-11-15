import uvicorn
import aiosqlite
from sqlalchemy import *
from fastapi import FastAPI
from databases import Database
from models.products import products_t
from models.categories import categories_t
from models.product_categories import product_categories_t

TESTING = True

if TESTING:
    DB_NAME = "db-test.sqlite"
    TEST_SQLALCHEMY_DB_URL = f"sqlite:///{DB_NAME}"
    db = Database(TEST_SQLALCHEMY_DB_URL)
else:
    DB_NAME = "db.sqlite"
    SQLALCHEMY_DB_URL = f"sqlite:///{DB_NAME}"
    db = Database(SQLALCHEMY_DB_URL)

app = FastAPI()


@app.on_event("startup")
async def startup():
    await db.connect()


@app.on_event("shutdown")
async def shutdown():
    await db.disconnect()


@app.get("/")
async def all_products():
    query = (
        select(
            [
                products_t.c.id,
                products_t.c.name,
                categories_t.c.name.label("category_name"),
                product_categories_t.c.category_id,
            ]
        )
        .select_from(products_t.outerjoin(categories_t.outerjoin(
            product_categories_t)))
        .order_by(desc(products_t.c.id))
    )
    return await db.fetch_all(query)


@app.get("/categories")
async def categories():
    query = (
        select(
            [
                categories_t.c.id,
                categories_t.c.name,
                product_categories_t.c.product_id,
                products_t.c.name.label("product_name")
            ]
        )
        .select_from(categories_t). \
        outerjoin(product_categories_t). \
        outerjoin(products_t)
        .order_by(desc(categories_t.c.id))
    )
    return await db.fetch_all(query)


@app.get("/products/{item_id}")
async def product(item_id: int):
    query = (
        select(
            [
                products_t.c.name.label("product_name"),
                categories_t.c.name.label("category_name"),
            ]
        )
        .select_from(products_t). \
        outerjoin(product_categories_t). \
        outerjoin(categories_t).\
        filter(products_t.c.id == item_id)
    )
    return await db.fetch_all(query)


@app.get("/products")
async def products():
    query = (
        select(
            [
                products_t.c.name.label("product_name"),
                categories_t.c.name.label("category_name"),
            ]
        )
        .select_from(products_t). \
        outerjoin(product_categories_t). \
        outerjoin(categories_t)
        .order_by(desc(products_t.c.id))
    )
    return await db.fetch_all(query)

if __name__ == "__main__":
    uvicorn.run(app, host="0.0.0.0", port=8000)

import asyncio
import httpx

from main import app
from fastapi.testclient import TestClient
from conftest import BASE_DIR


def test_post_detail(temp_db):
    item_id = 4
    with TestClient(app) as client:
        response = client.get(f"/products/{item_id}")
        print(response.url)
    assert response.status_code == 200
    assert response.json()[0]["product_name"] == "watermelon"
    assert response.json()[0]["category_name"] is None

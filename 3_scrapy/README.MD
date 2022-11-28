# Scrapy task
## Oz0n scraper w/proxy-via-tor
Will get oz0n top 100 items from phones category to calculate their OS versions usage.

### Configuration
I configured docker-compose to start 5 containers, so its 5 proxies every minute, but you can change it 
however you like. Also you can set your own bridges inside _tor/torrc_ configuration file.

### How to start
1. put chromedriver for your os in root directory
2. clone this project & cd
3. `docker-compose up`
4. `python -m venv venv`
5. `source venv/bin/activate`(linux) or `.\venv\scripts\activate` (windows)
6. `pip install -r requirements.txt`
7. `python3 main.py`
8. Results would be stored in results.csv in root directory
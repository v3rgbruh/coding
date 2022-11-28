from itemadapter import ItemAdapter


class OzonPipeline:
    def process_item(self, item, spider):
        with open('tmp/os.txt', 'a') as file:
            os = item["os_name"]
            ver = item["os_ver"]
            file.write(f'{{"os_name": "{os}", "os_ver": "{ver}"}}\n')
        return item

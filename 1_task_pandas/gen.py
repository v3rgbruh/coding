from random import randint


def generate_csv(num: int, filename: str = 'table'):
    temp_str = 'customer_id,product_id,timestamp\n'

    with open(filename + '.csv', mode="w") as file:
        for i in (str(randint(1, 25)) + ',' +
                  str(randint(1, 250)) + ',' +
                  str(randint(1172960000, 1172969999)) + '\n'
                  for _ in range(num)):
            temp_str += i
        file.write(temp_str)


if __name__ == '__main__':
    generate_csv(100000000)

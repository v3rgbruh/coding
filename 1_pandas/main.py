import pandas as pd

CSV_FILE = 'test'
COLUMNS = ['customer_id', 'product_id', 'timestamp']


class CustomerViews:
    def __init__(self, columns: list, table: str = 'table') -> None:
        try:
            table = pd.read_csv(table + '.csv')
        except BaseException:
            raise f"{table}.csv missing or does not exists, generate first by running 'python gen.py'"
        self.table = table
        try:
            df = pd.DataFrame(self.table, columns=columns)
        except BaseException:
            raise f"{columns} missing or have incorrect format. Should be list"
        self.df = df

    def group_by(self, field: str) -> pd.DataFrame.groupby:
        return self.df.groupby(field)

    def add_sessions(self) -> None:
        """
        Group dataframe by `customer_id`, make sorting by `timestamp`.
        Then add new column with unique `session_id` for each index.
        :return: None
        """
        sessions = 0
        original_indexes = self.df.index
        for _, group in self.group_by('customer_id'):
            df = group.sort_values('timestamp')
            pos = df.columns.get_loc('timestamp')

            # compare with first item, aka first visit by customer
            delta_first = df.iloc[1:, pos] - df.iat[0, pos]
            # Split sessions by 3 minutes interval
            df['session_id'] = delta_first // 180 + sessions
            # Set floats to int and replace NaN
            df['session_id'] = df['session_id'].fillna(sessions, limit=1).astype('int')
            # Make sessions unique
            sessions = df['session_id'].iat[-1] + 1
            # Restoring indexes
            df = df.sort_index(level=group.index)
            # Add 'session_id' column set floats as int and remove NaNs
            self.df = pd.concat([df, self.df], join='outer').dropna().astype('int')
        self.df = self.df.sort_index(level=original_indexes)

    def save_table(self, output: str = 'output'):
        self.df.to_csv(output + '.csv', index=False)

    def print_dataframe(self) -> None:
        print(self.df)


if __name__ == '__main__':
    customers = CustomerViews(columns=COLUMNS, table=CSV_FILE)
    customers.add_sessions()
    customers.save_table('out')
    customers.print_dataframe()

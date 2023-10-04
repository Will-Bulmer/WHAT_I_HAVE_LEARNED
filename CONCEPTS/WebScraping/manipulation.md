### Pandas
- https://www.datacamp.com/tutorial/web-scraping-using-python
```python
# Convert list of rows into a dataframe
df = pd.DataFrame(list_rows)
df.head(10)

# Split the '0' column into multiple columns at the comma position
df1 = df[0].str.split(',', expand=True)
df1.head(10) # Displays the first 10 rows in the dataframe

# Removes the sqaure brackets surrounding each row
df1[0] = df1[0].str.strip('[')
df1.head(10)

# Gets the table headers
col_labels = soup.find_all('th')

# Extract text in between HTML tags
all_header = []
col_str = str(col_labels)
cleantext2 = BeautifulSoup(col_str, "lxml").get_text()
all_header.append(cleantext2)
print(all_header)

# Convert list of headers into a pandas dataframe
df2 = pd.DataFrame(all_header)
df2.head()

# Split column '0' into multiple columns at the comma position
df3 = df2[0].str.split(',', expand=True)
df3.head()

# Concat two dataframe
frames = [df3, df1]

df4 = pd.concat(frames)
df4.head(10)

# Assign first row to be table header
df5 = df4.rename(columns=df4.iloc[0])
df5.head()

# For analysis, you can get the an overview of the data
df5.info()
df5.shape

# Drop all rows with missing values
df6 = df5.dropna(axis=0, how='any')

# Header is replicated as the first row
df7 = df6.drop(df6.index[0])
df7.head()

# More Cleaning
df7.rename(columns={'[Place': 'Place'},inplace=True) # Space after : is important.
df7.rename(columns={' Team]': 'Team'},inplace=True)
df7.head()

# Removing the closing bracket for cells in the 'Team' column
f7['Team'] = df7['Team'].str.strip(']')
df7.head()
```
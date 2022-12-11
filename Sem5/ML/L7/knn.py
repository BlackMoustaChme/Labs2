import pandas as pd
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier

df = pd.read_excel('knn_data.xlsx')

plt.scatter(df['x1'], df['x2'], c = df['class'])

X = df[['x1', 'x2']]
y = df['class']
# Разделим набор данных
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 0.2, random_state = 42)

neigh = KNeighborsClassifier(n_neighbors=3)
neigh.fit(X_train, y_train)# Для примера возьмем 3, можно выбрать другое число и посмотреть как изменится качество
print (neigh.fit(X_train, y_train))
neigh.score(X_test, y_test)# Доля правильных ответов
print (neigh.score(X_test, y_test))
import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sb
from sklearn import preprocessing
from sklearn.ensemble import RandomForestRegressor
from sklearn.inspection import permutation_importance
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsRegressor
from sklearn.svm import SVR
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import classification_report
from sklearn.model_selection import GridSearchCV

'''1.'''
df = pd.read_csv('dataset_var8.csv', sep=';', names=list(map(str, list(range(1, 8)))) + ['target'])
df.info()
df.drop('6', axis=1, inplace=True)
df = df.dropna()
df.info()

'''1.'''

'''2.'''
# sb.heatmap(df.corr(), annot = True)
# plt.savefig('MLRegrHeatMap.png', format='png')
# plt.show()
df = df.drop('7', axis=1)
df = df.drop('2', axis=1)
df = df.drop('3', axis=1)
# #
# sb.boxplot(data=df.drop('target', axis=1))
# # plt.savefig('MLRegrBox1.png', format='png')
# plt.show()
#
df = df.loc[df['1'] > -3]
#
# sb.boxplot(data=df.drop('target', axis=1))
# plt.savefig('MLRegrBox2.png', format='png')
# plt.show()
# '''2.'''
# #
# '''3.'''
X = df.drop('target', axis=1)
y = df['target']
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.4, random_state=10)
# '''3.'''
# # #
'''4., 5.'''
lr = LinearRegression()
lr.fit(X_train, y_train)
lr.score(X_test, y_test)
print(lr.score(X_test, y_test))
#
rfr = RandomForestRegressor(random_state=1, n_estimators=6)
rfr.fit(X_train, y_train.values.ravel())
rfr.score(X_test, y_test)
print(rfr.score(X_test, y_test))
#
knr = KNeighborsRegressor()
knr.fit(X_train, y_train)
knr.score(X_test, y_test)
print(knr.score(X_test, y_test))
#
regressor = SVR(kernel="linear", C=100, gamma="auto")
regressor.fit(X_train, y_train.values.ravel())
regressor.score(X_test, y_test)
print(regressor.score(X_test, y_test))
#
# lab_enc = preprocessing.LabelEncoder()
# # X_transformed = lab_enc.fit_transform(X_train)
# y_transformed = lab_enc.fit_transform(y_train)
# logr = LogisticRegression(C=5, max_iter=10000000, random_state=42).fit(X_train, y_transformed)
# logr.score(X_test, y_test)
# print(logr.score(X_test, y_test))
# '''4., 5.'''
# #
'''6.'''
results = permutation_importance(lr, X_train, y_train.values.ravel(), scoring='neg_mean_squared_error')
importance = results.importances_mean
for i,v in enumerate(importance):
    print('Feature: %0d, Score: %.5f' % (i,v))
plt.bar([x for x in range(len(importance))], importance)
# plt.savefig('MLRegrBar.png', format='png')
plt.show()
'''6.'''
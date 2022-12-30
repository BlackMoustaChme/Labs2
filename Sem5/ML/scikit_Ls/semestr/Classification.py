import pandas as pd
import seaborn as sb
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import scale
from sklearn.model_selection import GridSearchCV
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import classification_report
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import accuracy_score


'''1.'''
df = pd.read_csv('dataset_var8_class.csv', sep=';', names=list(map(str, list(range(1, 8)))) + ['target'])

df.head()
df.info()
df = df.dropna()
df.info()
'''1.'''

'''2.'''
# sb.heatmap(df.corr(), annot = True)
# plt.savefig('MLClassHeatmap.png', format='png')
# plt.show()
#
df = df.drop('7', axis=1)
#
# sb.boxplot(data=df.drop('target', axis=1))
# plt.savefig('MLClassBox1.png', format='png')
# plt.show()
#
df = df.loc[df['6'] < 3]
df = df.loc[df['6'] > -3]
# #
# sb.boxplot(data=df.drop('target', axis=1))
# plt.savefig('MLClassBox2.png', format='png')
# plt.show()
#
'''2.'''
#
'''3.'''
X = df.drop('target', axis=1)
y = df['target']
#
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.4, random_state=42)
# '''3.'''
# # #
# # '''4., 5.'''
rfc = RandomForestClassifier(random_state=42).fit(X_train, y_train)
print(f"Точность случайного леса: {accuracy_score(y_test, rfc.predict(X_test))}")
print(rfc.score(X_test, y_test))
print(classification_report(rfc.predict(X_test), y_test))
# #
knc = KNeighborsClassifier().fit(scale(X_train), y_train)
knc.score(scale(X_test), y_test)
print(f"Точность k ближайших соседей: {accuracy_score(y_test, knc.predict(X_test))}")
print(knc.score(scale(X_test), y_test))
print(classification_report(y_test, knc.predict(X_test)))
#
# '''4., 5.'''

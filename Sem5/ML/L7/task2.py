import pandas as pd
from sklearn.neighbors import KNeighborsClassifier
from sklearn.model_selection import KFold
from sklearn.model_selection import cross_val_score
from sklearn.preprocessing import scale

'''1.'''
data = pd.read_csv('wine.data.csv', names=['Class', 'Alcohol',
                                                'Malic acid', 'Ash',	'Alcalinity of ash',
                                                'Magnesium', 'Total phenols', 'Flavanoids',
                                                'Nonflavanoid phenols', 'Proanthocyanins',
                                                'Color intensity',  'Hue', 'OD280/OD315 of diluted wines',	'Proline' ])
y = data[['Class']]  # целевой класс
X = data.drop(['Class'], axis='columns')  # признаки
opt_list = []  # лист результатов оценки
'''1.'''

'''2.'''
kf = KFold(n_splits=5, shuffle=True, random_state=42)
for k in range(1, 51):
    neigh = KNeighborsClassifier(n_neighbors=k)
    opt_list.append(cross_val_score(neigh, X, y.values.ravel(), cv=kf, scoring='accuracy'))

'''3.'''
opt_what = pd.DataFrame(opt_list, range(1, 51)).mean(axis=1).sort_values(ascending=False)
top_opt = opt_what.head(1)
print(1, top_opt.index[0])  # k при котором получилось оптимальное качество
print(2, top_opt.values[0])  # само качество
'''2. , 3.'''

'''5.'''
X = scale(X)
opt_list_scale = []
for k in range(1, 51):
    neigh = KNeighborsClassifier(n_neighbors=k)
    opt_list_scale.append(cross_val_score(neigh, X, y.values.ravel(), cv=kf, scoring='accuracy'))

'''6.'''
opt_dataf_scale = pd.DataFrame(opt_list_scale, range(1, 51)).mean(axis=1).sort_values(ascending=False)
top_opt_scale = opt_dataf_scale.head(1)
print(1, top_opt_scale.index[0])  # k при котором получилось оптимальное качество
print(2, top_opt_scale.values[0])  # само качество
'''5. , 6'''



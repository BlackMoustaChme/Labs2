import pandas
import numpy as np
from sklearn.tree import DecisionTreeClassifier
from sklearn import preprocessing, metrics
from sklearn.model_selection import train_test_split

file = 'diabetes.csv'
# file_col = 'Pregnancies'


def fill_tree(x, y):
    clf = DecisionTreeClassifier(random_state=241)
    clf.fit(x, y)
    return clf


def cleaning(data):
    data.dropna(inplace=True)
    data = data.replace(to_replace=['male', 'female'], value=[1, 0])
    return data


def decision_tree(table, target):
    # print(len(table), len(target))
    model = fill_tree(table, target)
    predicted = model.predict(table)#test_table
    print(metrics.classification_report(target, predicted))#test_target
    # print(model)
    print(model.feature_importances_)


# def some_info(file, file_col):
#     data = pandas.read_csv(file, index_col=file_col)
#     survived_women = len(
#         data[(data['Sex'] == 'female') & (data['Survived'] == 1)])
#     print(survived_women / len(data[data['Survived'] == 1]) * 100)
#     print(len(data[data['Survived'] == 1]))
#     print(int(len(data[data['Survived'] == 1]) / len(data) * 100))


data = pandas.read_csv(file)
data = cleaning(data)
# some_info(file, file_col)
target = data['Outcome']
table = data[['Pregnancies', 'Glucose', 'BloodPressure', 'SkinThickness', 'Insulin', 'BMI', 'DiabetesPedigreeFunction', 'Age']]
X_train, X_test, y_train, y_test = train_test_split(table, target, test_size = 0.2, random_state = 42)
# table_train, table_test, target_train, target_test
normalized_table = preprocessing.normalize(table)
standardized_table = preprocessing.scale(table)
decision_tree(X_train, y_train)
decision_tree(normalized_table, target)
decision_tree(standardized_table, target)

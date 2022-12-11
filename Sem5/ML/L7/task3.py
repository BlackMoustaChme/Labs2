import numpy as np
from sklearn.datasets import load_boston
from sklearn.preprocessing import scale
from sklearn.model_selection import KFold
from sklearn.metrics import get_scorer_names
from sklearn.model_selection import cross_val_score
from sklearn.neighbors import KNeighborsRegressor

'''1.'''
boston_dataset = load_boston()
observations = boston_dataset.data
targets = boston_dataset.target
'''1.'''

'''2.'''
observations_scaled = scale(observations)
'''2.'''

'''3.'''
p_values = np.linspace(1.0, 10.0, num=200)
kf = KFold(len(observations_scaled), shuffle=True, random_state=42)


cv_accuracy = [cross_val_score(estimator=KNeighborsRegressor(n_neighbors=5, weights='distance', p=p_i, metric='minkowski'), X=observations_scaled, y=targets, cv=kf, scoring='neg_mean_squared_error').mean() for p_i in p_values]
'''3.'''

'''4.'''
best_p = p_values[int(max(cv_accuracy))]


print("p = ", best_p)
'''4.'''
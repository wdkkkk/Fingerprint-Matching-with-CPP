# Fingerprint-Matching-with-CPP
The Python interface for fingerprint matching algorithm, implemented with C++.
## Install
```sh
# clone the repo to your work directory
git clone https://github.com/wdkkkk/Fingerprint-Matching-with-CPP.git
# install the module with pip
cd Fingerprint-Matching-with-CPP/match
python setup.py install
```

## Usage
```python
import match
import numpy as np

position_threshold = 5
angle_threshold = np.pi/6
regest = np.array([[1,2,0.123],[2,3,1.234]])
test = np.array([[3,5,-0.633],[4,7,0.768]])
match_score = match.match(regest, test, 5, np.pi/6)
```

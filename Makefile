release: sdist
	python3 -m twine upload --repository testpypi dist/* 

sdist: clean
	python setup.py sdist

clean: 
	rm -rf dist

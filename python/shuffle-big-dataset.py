import os
import random

# https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
def fisher_yates_shuffle(dataset=list()):
	size = len(dataset)
	for i in range(size-1):
		j = random.randint(i, size-1)
		dataset[i], dataset[j] = dataset[j], dataset[i]

def twice_pass_shuffle(dataset, total_size, M):
	# first pass
	p = [[] for _ in range(M)]
	for i in range(total_size):
		j = random.randint(0, M-1)
		p[j].append(dataset[i])
	# second pass
	result = []
	for j in range(M):
		fisher_yates_shuffle(p[j])
		result.extend(p[j])
	return result

if __name__ == '__main__':
	l = [i for i in range(1,101)]
	print("befor shuffle:\n", l)
	result = twice_pass_shuffle(l, total_size=100, M=10)
	print("\nshuffle result:\n", result)
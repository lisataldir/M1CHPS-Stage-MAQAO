#!/usr/bin/env python

import sys
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.patches import Rectangle

def occurrences(tableau):
    dico = {}
    for elmt in tableau:
        if elmt not in dico:
            dico[elmt] = 1
        else:
            dico[elmt] += 1
    return dico


def color(key):
	color = []
	for k in key:
		if (k[-2] == 'P'):
			color.append('green')
			continue;
		if (k[0] == 'V' and k[-2] != 'P'):
			color.append('orange')
			continue;
		else:
			color.append('gray')
			continue;
	return color
	

filename = sys.argv[1]
tab = []

file = open(filename, 'r')
for line in file:
    tab += [[elt for elt in line.split()]]

tab = np.array(tab)
instructions = tab[:, 1]
dico = occurrences(instructions)
   
fig, ax = plt.subplots()
ax.bar(dico.keys(), dico.values(), color=color(dico.keys()), ec="k")
ax.grid(True, which='both', linestyle='-', alpha=0.5)

ax.set_xlabel('Instructions')
ax.set_ylabel('Occurrences')
handles = [Rectangle((0,0),1,1,color=c, ec='k') for c in ['green', 'orange', 'gray']]
labels= ['Vectorisé','Vectorisable','Non vectorisable']
plt.legend(handles, labels)
plt.show()

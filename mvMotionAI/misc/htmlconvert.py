import re
import os

tutorialDir = 'D:/mvMotionAI/mvMotionAI/examples-src/tutorial3'
fileName = 'CustomActionGLMain.cpp'
outputFileName = 'c.txt'

os.chdir(tutorialDir)
andconvert = re.compile('&')
space3 = re.compile('  ')
tabc = re.compile('\t')
ltc = re.compile('<')
gtc = re.compile('>')
sc = re.compile('\n')

code = open(fileName,'r')
output = open(outputFileName, 'w')
line = code.readline()
i = 0
temp = ''
while len(line) > 0:
   temp = andconvert.sub('&amp;',line)    
   temp = ltc.sub('&lt;',temp)
   temp = tabc.sub('&nbsp;&nbsp;',temp)
   temp = space3.sub('&nbsp;&nbsp;',temp)    
   temp = gtc.sub('&gt;',temp) 
   temp = sc.sub('<br />',temp)
   output.write(temp)
   output.write('\n')
   line = code.readline()
   i += 1
code.close()
output.close()

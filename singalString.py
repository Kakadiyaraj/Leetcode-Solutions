#Write a program that reads names of two python files and strips the extension. The filenames are then concatenated to form a single string. The program then prints 'True' if the newly generated string is a palindrome, or prints 'False' otherwise.

name1 = input('Enter a first file name : ')
name2 = input('Enter a second file name : ')
name1 = name1.replace('.py','')
name2 = name2.replace('.py','')
name = name1+name2
print('Newly generated string : ',name)
if name==name[::-1]:
  print('Output : True')
else:
  print('Output : False')

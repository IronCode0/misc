
sentence =input('Enter value: ')
new_sentence =""

for word in sentence.split(" "):
    new_word=word[1:] + word[0] + "ay"
    new_sentence = new_sentence + " " + new_word
print(new_sentence.rstrip())




value =int(input('Enter value: '))
# a=20, b=10, c=30
if value <= 20:
    print('a = ',value)
else:
    print('a = 20')
    value =value-20
    if value <= 10:
        print('b = ',value)
    else:
        print('b = 10')
        value =value-10
        if value <= 30:
            print('c = ',value)
        else:
            print('c = 30')

            
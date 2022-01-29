#!/usr/bin/python3

#my first ever python code
#finding  best word to start 'vaajoor.ir' with

textFile = open("persian-words.txt", 'r')
wordsWithDif = textFile.read()
wordsWithDif = wordsWithDif.splitlines(1)
words = [word.split(":", 1)[0] for word in wordsWithDif]
letters =  ['ا' ,'ی' ,'ن' ,'ر' ,'د' ,'م' ,'ه' ,'و' ,'ت' ,'ب' ,'س' ,'ش' ,'ک' ,'ز' ,'ل' ,'گ' ,'ق' ,'ف' ,'خ' ,'ع' ,'ک' ,'ح' ,'ج' ,'آ' ,'پ' ,'چ' ,'ض' ,'ط' ,'ص' ,'غ' ,'ظ' ,'ث' ,'ذ' ,'ی' ,'ژ']
bestScore = 100000000
for word in words:
    if len(word) == 5:
        score = 0
        wordset = set(word)
        for l in wordset:
            if letters.__contains__(l):
                score += letters.index(l)
        if score < bestScore:
            bestScore = score
            print(word)
print(bestScore)

i_words = int(input())
for i in range(i_words):
    word = input()
    if len(word)>10:
        print(f"{word[0]}{len(word[1:len(word)-1])}{word[len(word)-1]}")
    else: 
        print(word)
import string

# Encryption using ASCII table

pierwszy = ('ada', [1, 1, 1])
drugi = ('mysz', [1, 2, 3])
trzeci = ('Ala ma kota', [1, 2, 3])

def lenBezSpacji(ciag): # Number of characters in the string excluding spaces
    wynik=""
    for znak in ciag:
        if znak != " ":
            wynik=wynik+znak
    return len(wynik)


def szyfruj(krotka): # Encrypting function
    ciag = krotka[0]
    dlugoscCiagu=lenBezSpacji(ciag)

    klucz = krotka[1]
    iloscKluczy = len(klucz)

    i = 0
    zaszyfrowany = ""

    for znak in ciag:
        if znak != " ":
            if znak not in string.ascii_lowercase:
                zaszyfrowany += znak
            else:
                po=ord(znak)+klucz[i % iloscKluczy]
                if po > 122:
                    po=po-122+96
                zaszyfrowany+=chr(po)
        else:
            zaszyfrowany += " "
        i += 1

    print(krotka, "->", zaszyfrowany)


szyfruj(pierwszy)
szyfruj(drugi)
szyfruj(trzeci)



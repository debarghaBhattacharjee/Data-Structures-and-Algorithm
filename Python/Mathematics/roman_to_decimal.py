# PROBLEM STATEMENT: print the decimal equivalent of a roman numeral string.
# EXAMPLE: VIII = 8, XVIII = 18

def get_base_decimal(roman: str) -> int:
    """
    Method to get base decimal equivalent of some 
    basic roman numerals.
    """
    if roman == "I":
        return 1
    elif roman == "II":
        return 2
    elif roman == "III":
        return 3
    elif roman == "IV":
        return 4
    elif roman == "V":
        return 5
    elif roman == "VI":
        return 6
    elif roman == "VII":
        return 7
    elif roman == "VIII":
        return 8
    elif roman == "IX":
        return 9
    elif roman == "X":
        return 10
    elif roman == "L":
        return 50
    elif roman == "C":
        return 100
    elif roman == "D":
        return 500
    elif roman == "M":
        return 1000
    else: 
        return -1
    return -1


def roman_to_decimal(roman: str) -> int:
    """
    Method to convert a roman string to its equivalent
    decimal integer.
    """
    decimal = 0
    i = 0
    while i < len(roman):
        # Here, 
        #    s1 = decimal equivalent of current roman literal
        #    s2 = decimal equivalent of next literal
        s1 = get_base_decimal(roman[i])
        if i + 1 < len(roman):
            # If there is a roman literal next, simply update 
            # decimal as: decimal = decimal + s1
            s2 = get_base_decimal(roman[i+1])
            if s1 >= s2:
                # If s1 >= s2, then update decimal as: 
                # decimal = decimal - s1
                decimal = decimal + s1
                i = i + 1
            else:
                # If s2 > s1, then update decimal as: 
                # decimal = decimal + s2 - s1
                decimal = decimal + s2 - s1
                i = i + 2
        else:
            # If there is no next roman literal, simply update 
            # decimal as: decimal = decimal + s1
            decimal = decimal + s1
            i = i + 1
    return decimal
    
# Driver program
if __name__ == "__main__": 
    roman = str(input("input: "))
    decimal = roman_to_decimal(roman)
    print(decimal)
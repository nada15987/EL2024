

def get_bits():
    lst =[]
    for i in range(8):
        bit= input(f"Please enter Bit {i} mode (in/out) : ")
        if bit == 'in':
            lst.append(0)
        elif bit =='out':
            lst.append(1)
        else: 
            print("error")
            break
    return lst

def code_out():
    x=get_bits()
    inv_x = x[::-1] #reverse the list
    # Convert the list of integers to a string and concatenate with '0b'
    bit_string = ''.join(map(str, inv_x))
    print ("the generated GPIO Initialization function:")
    code= f"""\
        void Init_PORTA_DIR (void)
        {{
         DDRA= 0b{bit_string};
        }}"
    """
    return code


print(code_out())

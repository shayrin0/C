
/*
    Extract bit positions from 9th to 14th in a given data
    and save it in to another variable.

    Procedure:
    1. Shift the identified portion to right hand side until 
    it touches the lsb (0th bit)
    2. Mask the value to extract only 6 bits [5:0] and then
    save it in to another variable
*/
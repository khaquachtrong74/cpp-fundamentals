#!/bin/bash

# Make dir
# create *.cpp and *.h, and main function
# create bash run file and chmod +x with at it

NAME_FILE=$1
if [[ -z "$NAME_FILE" ]];then
	echo "Error: NAME_FILE is eMpty!"
	exit 1
fi
UPPER_CASE=$(echo $NAME_FILE | tr '[:lower:]' '[:upper:]')
LOWER_CASE=$(echo $NAME_FILE | tr '[:upper:]' '[:lower:]')
FIRST_CHAR=${NAME_FILE:0:1}
ENTIRE_CHAR=${NAME_FILE:1}
NAME_FOLDER="$FIRST_CHAR$ENTIRE_CHAR"
mkdir "$NAME_FOLDER"
if [ $? -ne 0 ]; then
	echo "fatal"
else
	echo " Make dir success!"
	cd "$NAME_FOLDER"
	touch ./"$LOWER_CASE".h && touch ./"$LOWER_CASE".cpp && touch ./main.cpp && touch run.bash

# write default text for some file
{
echo "#ifndef _${UPPER_CASE}_H"
echo "#define _${UPPER_CASE}_H"
echo '#endif'
} >> "$LOWER_CASE".h

{
echo "#include \"./${LOWER_CASE}.h\""
} >> "$LOWER_CASE".cpp

{
echo  """
#include<iostream>
#include \"./"${LOWER_CASE}".h\"
using namespace std;
int main(){

return 0;
}
"""
} >> main.cpp
	
{
echo """
#!/bin/bash
# Just base script to run file main
g++ *.cpp -o a.out
"""
} >> run.bash
chmod +x run.bash
fi

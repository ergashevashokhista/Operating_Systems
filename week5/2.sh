#!/bin/bash 

#create the numbers file                                                   
if test ! -f newNumbers
then
    echo 0 > newNumbers
fi

#Just locks and don't let others interrupt :)
if ln newNumbers newNumbers.lock
  then                                                                    
  #Repeat 100 times to see fun
  for i in `seq 1 100`;
  do
    #Read and increase last number
    LASTNUMBER=`tail -1 newNumbers`
    LASTNUMBER=$((LASTNUMBER+1))

    echo $LASTNUMBER >> newNumbers
  done

  #Unlock
  rm newNumbers.lock
fi
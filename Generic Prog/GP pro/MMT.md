# Classes 
- flights 
    - type of flight [enum] : 
        - one way :
            - contains: 
                - from 
                - To 
                - departure date

        - round trip :
                - from 
                - To 
                - departure date
                - Return Date
                
        - multicity :
            - it is a struct of 
                - from 
                - to 
                - departure 

        Common : 
             - number of travellers 
             - Fare type 
             - Class 
            
- hotels 
    - types [ enum ]: 
        - Upto 4 rooms 
            - room constraint = 4
        - Group 
            - more than 4
        - Common: 
            - location
            - check-in
            - checkout 
            - rooms and guests (class type probbaly (adult,rooms,children))
            - price-per-night
            
- homestays and villas 
    - location
    - check-in
    - checkout 
    - rooms and guests (class type probbaly (adult,rooms,children))
    - price-per-night

- holiday packages 
    - Flights 
    - array of Hotels , homestays and villas 
    - Filter 
        - duration 
        - hotel cat
        - bool flights
        
- trains
    - Book train tickets
        - From 
        - to 
        - date 
        - class 
    - check pnr status 
    - Live train status .
    
- buses
    - From 
    - TO 
    - Date

- cabs 
    - From 
    - TO 
    - Departure 
    - Pickup Time 
    - Return Time 

(base class)
- roomsAndGuests 
    - rooms 
    - adults 
    - children

(base class)
-dataAndTime 
    - date 
    - time

(base class)
- location 
    - city 
    - state 
    - country 
    - pincode

(base class)
- fareType 
    - economy 
    - premium economy 
    - business 
    - first class

<template function>
- filter(object,filters)

<template function>
- sort(object,sortType)

template



- Forex Card and currency 
    NA


- Foreign Insurance 
    NA

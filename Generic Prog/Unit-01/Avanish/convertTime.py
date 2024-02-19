from datetime import datetime

def convertTime(time_int:int)->str:
    dt_object = datetime.utcfromtimestamp(unix_timestamp)
    formatted_time = dt_object.strftime('%Y-%m-%d %H:%M:%S UTC')
    return formatted_time

unix_timestamp = 1612132800

print(convertTime(unix_timestamp))
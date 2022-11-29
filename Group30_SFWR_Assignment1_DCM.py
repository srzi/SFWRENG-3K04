#!/usr/bin/env python
# coding: utf-8

# In[ ]:

#pw = ***, modes screen destroyed and returned, corresponding parameters for each mode done
#11/17/2022
#BY AHMED ABDELHALIM 400313465 abdela55 / SARA ARMANZI 400324304 armanazs
import json
from tkinter import *
from tkinter import messagebox
import ast
from tkinter import ttk
from tokenize import Special
import serial
import decimal
from decimal import Decimal
import time
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg

import math
import struct
wind = Tk()
wind.title("Login")
wind.geometry('925x500+300+150')
wind.configure(bg='#fff')
wind.resizable(False, False)
serial_port = "COM6"
frame = Frame(wind, width=350, height=350, bg='white')
frame.place(x=250, y=100)

heading1 = Label(text='Pacemaker DCM Login', fg='black', bg='#fff',
                 font=('Microsoft YaHei UI Light', 16, 'bold'))
heading1.place(x=35, y=10)

heading = Label(frame, text='Login', fg='black', bg='white', font=('Microsoft YaHei UI Light', 23, 'bold'))
heading.place(x=165, y=5)




## LOGIN CHECKER
def signin():
    username=user.get()
    password=passw.get()

    

    file = open('LOGIN_DATA.txt', 'r')
    d = file.read()
    r = ast.literal_eval(d)
    file.close()
###############################################################
           #                  MODES                   

###############################################################
     
    def AOO(): #function when button is clicked   
        window.destroy()
        
        global master
        master = Tk()
        master.geometry("800x600+300+100")
        master.title("AOO")
        global LOWER_RATE_LIMIT
        global UPPER_RATE_LIMIT
        global B_AMPLITUDE
        global PULSE_WIDTH
        global SET_CURRENT_MODE
        SET_CURRENT_MODE = 'AOO'
        Label(master, text = "SET VALUES BELOW", font = ("Calibri", 13)).pack()
        Label(master, text = "").pack()

        Label(master, text = "Lower Rate Limit (ppm)").pack()
       
        CHOICES = [
            "30","35","40","45","50","51","52","53","54","55","56","57","58","59","60","61","62","63","64","65","66","67","68","69","70",
            "70","71","72","73","74","75","76","77","78","79","80","81","82","83","84","85","86","87","88","89",
            "90","95","105","110","115","120","125","130","135","140","145","150","155","160","165","170","175",
        ]
        choice = DoubleVar()
        choice.set(CHOICES[0])
        list = ttk.Combobox(master, value= CHOICES)
        list.current(14)
        list.bind("<<ComboboxSelected>>")
        list.pack() 
        Label(master, text = "").pack()

        
        
        
        
        Label(master, text = "Upper Rate Limit (ppm)").pack()
        UPPER_RATE_LIMIT = Scale(master, from_=50, to =175, resolution=5, orient=HORIZONTAL)
        UPPER_RATE_LIMIT.set(120)
        UPPER_RATE_LIMIT.pack()
        Label(master, text = "").pack()

        
        
        
        
        Label(master, text = "Atrial Amplitude (V)").pack()
        CHOICES1 =[
        "0","0.1","0.2","0.3","0.4","0.5","0.6","0.7","0.8","0.9","1.0","1.1","1.2","1.3","1.4","1.5","1.6",
        "1.7","1.8","1.9","2.0","2.1","2.2","2.3","2.4","2.5","2.6","2.7","2.8","2.9","3.0","3.1","3.2","3.3",
        "3.4","3.5","3.6","3.7","3.8","3.9","4.0","4.1","4.2","4.3","4.4","4.5","4.6","4.7","4.8","4.9","5.0"
    ]
        choice1 = DoubleVar()
        choice1.set(CHOICES1[0])
        list1 = ttk.Combobox(master, value= CHOICES1)
        list1.current(29)
        list1.bind("<<ComboboxSelected>>")
        list1.pack()
        Label(master, text = "").pack()

        
        
        
        
        Label(master, text = "Atrial Pulse Width (ms)").pack()
        CHOICES2 = [
        "1","2","3","4","5","6","7","8","9","10", "11","12","13","14","15","16","17","18","19","20", "21","22","23","24","25","26","27","28","29","30"
    ]
        choice2 = DoubleVar()
        choice2.set(CHOICES2[0])
        list2 = ttk.Combobox(master, value= CHOICES2)
        list2.current(4)
        list2.bind("<<ComboboxSelected>>")
        list2.pack()
        Label(master, text = "").pack()

        
        def connect2():
            global window
            window = Tk()
            window.geometry('925x320+300+150')
            
            Label(window, text = "Please select your mode:", font = ("Calibri", 13)).place(x=400,y=10)

        #############################################BUTTONS FOR MODES

            button2 = Button(window,width=20, pady=6,  text= "1.    AOO",bg='white', fg='black', border=1,command=AOO).place(x=300,y=40) #input button
            
            button3 = Button(window,width=20, pady=6,  text= "2.    VVI",bg='white', fg='black', border=1,command=VVI).place(x=300,y=100) #input button

            button4 = Button(window,width=20, pady=6,  text= "3.    VOO",bg='white', fg='black', border=1,command=VOO).place(x=300,y=160) #input button

            button5 = Button(window,width=20, pady=6, text= "4.     AAI",bg='white', fg='black', border=1,command=AAI).place(x=300,y=220) #input button
            
            button6 = Button(window,width=20, pady=6, text= "5.     AOOR",bg='white', fg='black', border=1,command=AOOR).place(x=460,y=40) #input button
            button7 = Button(window,width=20, pady=6, text= "6.     VOOR",bg='white', fg='black', border=1,command=VOOR).place(x=460,y=100) #input button       
            button8 = Button(window,width=20, pady=6, text= "7.     AAIR",bg='white', fg='black', border=1,command=AAIR).place(x=460,y=160) #input button
            button9 = Button(window,width=20, pady=6, text= "8.     VVIR",bg='white', fg='black', border=1,command=VVIR).place(x=460,y=220) #input button
            Button(window, width=20, pady=2, text="Logout",bg='black', fg='white', border=1, command=window.destroy).place(x=400, y=280) #button to close the window
            Label(window, text = "Pacemaker User:  %s" % (username),font = ("Calibri", 13)).pack(side = LEFT )
            Label(window, text = "CONNECTED TO PACEMAKER",fg = 'green' ,font = 'Helvetica 9 bold').pack(side = RIGHT)

            master.destroy()

            
            window.mainloop()
        def DISPLAY():
            global LOWER_RATE_LIMIT
            global UPPER_RATE_LIMIT
            global B_AMPLITUDE
            global PULSE_WIDTH
            LOWER_RATE_LIMIT = list.get()
            B_AMPLITUDE = list1.get()
            PULSE_WIDTH = list2.get()
            SET_VALS()
            Label(master, text = "Your values have been saved", font = ("Calibri", 13)).place(x=450,y=400)

        Button(master, text = "Save", width="3", height = "1", command = DISPLAY).pack()
        Button(master, text = "Load", width="3", height = "1", command = ACCESS_LOAD).pack()
        Button(master, text="ECG", command=ECG).pack() #button to close the window
        Button(master, text="Back", command= connect2).pack() #button to close the window
        Label(master, text = "Pacemaker User:  %s" % (username),font = ("Calibri", 12)).pack(side = LEFT )
        master.mainloop()

        Label(master, text = "").pack()


   ###############################################################
##############################################################
# 
# 
# 
#      
        
        
    def VOO(): #function when button is clicked   
        window.destroy()

        global master
        master = Tk()
        master.geometry("800x600+300+100")
        master.title("VOO")
        global LOWER_RATE_LIMIT
        global UPPER_RATE_LIMIT
        global B_AMPLITUDE
        global PULSE_WIDTH
        global SET_CURRENT_MODE
        SET_CURRENT_MODE = 'VOO'

        Label(master, text = "SET VALUES BELOW", font = ("Calibri", 13)).pack()
        Label(master, text = "").pack()

        
        
        
        
        
        
        Label(master, text = "Lower Rate Limit (ppm)").pack()
        CHOICES = [
            "30","35","40","45","50","51","52","53","54","55","56","57","58","59","60","61","62","63","64","65","66","67","68","69","70",
            "70","71","72","73","74","75","76","77","78","79","80","81","82","83","84","85","86","87","88","89",
            "90","95","105","110","115","120","125","130","135","140","145","150","155","160","165","170","175",
        ]
        choice = DoubleVar()
        
        choice.set(CHOICES[0])
        
        list = ttk.Combobox(master, value= CHOICES)
        
        list.current(14)
        
        list.bind("<<ComboboxSelected>>")
        
        list.pack() 

        Label(master, text = "").pack()

        
        
        Label(master, text = "Upper Rate Limit (ppm)").pack()
        UPPER_RATE_LIMIT = Scale(master, from_=50, to =175, resolution=5, orient=HORIZONTAL)
        UPPER_RATE_LIMIT.set(120)
        UPPER_RATE_LIMIT.pack()
        Label(master, text = "").pack()





        Label(master, text = "Ventricular Amplitude (V)").pack()
        CHOICES1 = [
        "0","0.1","0.2","0.3","0.4","0.5","0.6","0.7","0.8","0.9","1.0","1.1","1.2","1.3","1.4","1.5","1.6",
        "1.7","1.8","1.9","2.0","2.1","2.2","2.3","2.4","2.5","2.6","2.7","2.8","2.9","3.0","3.1","3.2","3.3",
        "3.4","3.5","3.6","3.7","3.8","3.9","4.0","4.1","4.2","4.3","4.4","4.5","4.6","4.7","4.8","4.9","5.0"
    ]
        choice1 = DoubleVar()
        choice1.set(CHOICES1[0])
        list1 = ttk.Combobox(master, value= CHOICES1)
        list1.current(29)
        list1.bind("<<ComboboxSelected>>")
        list1.pack()
        Label(master, text = "").pack()






        Label(master, text = "Ventricular Pulse Width (ms)").pack()
        CHOICES2 = [
        "1","2","3","4","5","6","7","8","9","10", "11","12","13","14","15","16","17","18","19","20", "21","22","23","24","25","26","27","28","29","30"
    ]
        choice2 = DoubleVar()
        choice2.set(CHOICES2[0])
        list2 = ttk.Combobox(master, value= CHOICES2)
        list2.current(4)
        list2.bind("<<ComboboxSelected>>")
        list2.pack()
        Label(master, text = "").pack()
        
        def connect2():
            global window
            window = Tk()
            window.geometry('925x320+300+150')
            
            Label(window, text = "Please select your mode:", font = ("Calibri", 13)).place(x=400,y=10)

        #############################################BUTTONS FOR MODES

            button2 = Button(window,width=20, pady=6,  text= "1.    AOO",bg='white', fg='black', border=1,command=AOO).place(x=300,y=40) #input button
            
            button3 = Button(window,width=20, pady=6,  text= "2.    VVI",bg='white', fg='black', border=1,command=VVI).place(x=300,y=100) #input button

            button4 = Button(window,width=20, pady=6,  text= "3.    VOO",bg='white', fg='black', border=1,command=VOO).place(x=300,y=160) #input button

            button5 = Button(window,width=20, pady=6, text= "4.     AAI",bg='white', fg='black', border=1,command=AAI).place(x=300,y=220) #input button
            
            button6 = Button(window,width=20, pady=6, text= "5.     AOOR",bg='white', fg='black', border=1,command=AOOR).place(x=460,y=40) #input button
            button7 = Button(window,width=20, pady=6, text= "6.     VOOR",bg='white', fg='black', border=1,command=VOOR).place(x=460,y=100) #input button       
            button8 = Button(window,width=20, pady=6, text= "7.     AAIR",bg='white', fg='black', border=1,command=AAIR).place(x=460,y=160) #input button
            button9 = Button(window,width=20, pady=6, text= "8.     VVIR",bg='white', fg='black', border=1,command=VVIR).place(x=460,y=220) #input button
            Button(window, width=20, pady=2, text="Logout",bg='black', fg='white', border=1, command=window.destroy).place(x=400, y=280) #button to close the window
            Label(window, text = "Pacemaker User:  %s" % (username),font = ("Calibri", 13)).pack(side = LEFT )
            Label(window, text = "CONNECTED TO PACEMAKER",fg = 'green' ,font = 'Helvetica 9 bold').pack(side = RIGHT)

            master.destroy()

            
            window.mainloop()
        
        
        
        def DISPLAY():
            global LOWER_RATE_LIMIT
            global UPPER_RATE_LIMIT
            global B_AMPLITUDE
            global PULSE_WIDTH
            LOWER_RATE_LIMIT = list.get()
            B_AMPLITUDE = list1.get()
            PULSE_WIDTH = list2.get()
            SET_VALS()
            Label(master, text = "Your values have been saved", font = ("Calibri", 13)).place(x=450,y=400)
            # print("_____________________________________")
            # print("The values for VOO :")
            # print("LOWER RATE LIMIT : ",LOWER_RATE_LIMIT)
            # print("UPPER RATE LIMIT : ", UPPER_RATE_LIMIT.get()) 
            # print("VENT AMPLITUDE : ",B_AMPLITUDE)
            # print("VENT PULSE WIDTH : ",PULSE_WIDTH)
            # print("_____________________________________")
        Button(master, text = "Save", width="3", height = "1", command = DISPLAY).pack()
        Button(master, text = "Load", width="3", height = "1", command = ACCESS_LOAD).pack()
        Button(master, text="ECG", command=ECG).pack() #button to close the window
        Button(master, text="Back", command=connect2).pack() #button to close the window
        Label(master, text = "Pacemaker User:  %s" % (username),font = ("Calibri", 13)).pack(side = LEFT )

        Label(master, text = "").pack()   
        



    ###############################################################
############################################################## 
# 
# 
# 
#    
    def AAI(): #function when button is clicked 
        window.destroy() ##added in each function to close modes window, back reopens  
        global SET_CURRENT_MODE
        SET_CURRENT_MODE = 'AAI'
        global master
        master = Tk()
        master.geometry("800x900+300+100")
        master.title("AAI")
        global LOWER_RATE_LIMIT
        global UPPER_RATE_LIMIT
        global B_AMPLITUDE
        global PULSE_WIDTH
        global ARP_VRP
        global PVARp
        global atrSENS
        global Hyster
        global rateSmoot

        Label(master, text = "SET VALUES BELOW", font = ("Calibri", 13)).pack()
        Label(master, text = "").pack()

        
        
        Label(master, text = "Lower Rate Limit (ppm)").pack()
        CHOICES = [
            "30","35","40","45","50","51","52","53","54","55","56","57","58","59","60","61","62","63","64","65","66","67","68","69","70",
            "70","71","72","73","74","75","76","77","78","79","80","81","82","83","84","85","86","87","88","89",
            "90","95","105","110","115","120","125","130","135","140","145","150","155","160","165","170","175",
        ]
        choice = DoubleVar()
        choice.set(CHOICES[0])
        list = ttk.Combobox(master, value= CHOICES)
        list.current(14)
        list.bind("<<ComboboxSelected>>")
        list.pack() 
        Label(master, text = "").pack()

        
        
        
        Label(master, text = "Upper Rate Limit (ppm)").pack()
        UPPER_RATE_LIMIT = Scale(master, from_=50, to =175, resolution=5, orient=HORIZONTAL)
        UPPER_RATE_LIMIT.set(120)

        UPPER_RATE_LIMIT.pack()
        Label(master, text = "").pack()

       
       
       
        Label(master, text = "Atrial Amplitude (V)").pack()
        CHOICES1 =[
        "0","0.1","0.2","0.3","0.4","0.5","0.6","0.7","0.8","0.9","1.0","1.1","1.2","1.3","1.4","1.5","1.6",
        "1.7","1.8","1.9","2.0","2.1","2.2","2.3","2.4","2.5","2.6","2.7","2.8","2.9","3.0","3.1","3.2","3.3",
        "3.4","3.5","3.6","3.7","3.8","3.9","4.0","4.1","4.2","4.3","4.4","4.5","4.6","4.7","4.8","4.9","5.0"
    ]
        choice1 = DoubleVar()
        choice1.set(CHOICES1[0])
        list1 = ttk.Combobox(master, value= CHOICES1)
        list1.current(29)
        list1.bind("<<ComboboxSelected>>")
        list1.pack()
        Label(master, text = "").pack()

        
        
        
        
        
        Label(master, text = "Atrial Pulse Width (ms)").pack()
        CHOICES2 = [
        "1","2","3","4","5","6","7","8","9","10", "11","12","13","14","15","16","17","18","19","20", "21","22","23","24","25","26","27","28","29","30"
    ]
        choice2 = DoubleVar()
        choice2.set(CHOICES2[4])
        list2 = ttk.Combobox(master, value= CHOICES2)
        list2.current(0)
        list2.bind("<<ComboboxSelected>>")
        list2.pack()
        Label(master, text = "").pack()
        


        
        
        
        Label(master, text = "ARP(ms)").pack()
        CHOICES3 = [
            "150","160","170","180","190","200","210","220","230","240","250","260","270","280","290","300","310","320","330","340","350","360","370","380","390","400","410","420","430","440","450","460","470","480","490","500",
        ]
        choice3 = DoubleVar()
        choice3.set(CHOICES3[0])
        list3 = ttk.Combobox(master, value= CHOICES3)
        list3.current(17)
        list3.bind("<<ComboboxSelected>>")
        list3.pack()
        Label(master, text = "").pack()
        
        
        
        
        
        Label(master, text = "Atrial sensistivity").pack()
        CHOICES4 = [
        "0","0.1","0.2","0.3","0.4","0.5","0.6","0.7","0.8","0.9","1.0","1.1","1.2","1.3","1.4","1.5","1.6",
        "1.7","1.8","1.9","2.0","2.1","2.2","2.3","2.4","2.5","2.6","2.7","2.8","2.9","3.0","3.1","3.2","3.3",
        "3.4","3.5","3.6","3.7","3.8","3.9","4.0","4.1","4.2","4.3","4.4","4.5","4.6","4.7","4.8","4.9","5.0"
    ]
        choice4 = DoubleVar()
        choice4.set(CHOICES4[0])
        list4 = ttk.Combobox(master, value= CHOICES4)
        list4.current(2)
        list4.bind("<<ComboboxSelected>>")
        list4.pack()
        Label(master, text = "").pack()
        
        
        
        
        Label(master, text = "Hystereisis").pack()
        CHOICES5 = ["OFF","Same as LRL"]
        choice5 = DoubleVar()
        choice5.set(CHOICES5[0])
        list5 = ttk.Combobox(master, value= CHOICES5)
        list5.current(0)
        list5.bind("<<ComboboxSelected>>")
        list5.pack()
        Label(master, text = "").pack()
        




        Label(master, text = "Rate smoothing").pack()
        rateSmoot = Scale(master, from_=0, to =25,resolution=3.07, orient=HORIZONTAL)
        rateSmoot.set(0)
        rateSmoot.pack()
        Label(master, text = "").pack()
        
        



        Label(master, text = "PVARP").pack()
        PVARp = Scale(master, from_=150, to =500,resolution=10, orient=HORIZONTAL)
        PVARp.pack()
        PVARp.set(250)
        Label(master, text = "").pack()
        def connect2():
            global window
            window = Tk()
            window.geometry('925x320+300+150')
            
            Label(window, text = "Please select your mode:", font = ("Calibri", 13)).place(x=400,y=10)

        #############################################BUTTONS FOR MODES

            button2 = Button(window,width=20, pady=6,  text= "1.    AOO",bg='white', fg='black', border=1,command=AOO).place(x=300,y=40) #input button
            
            button3 = Button(window,width=20, pady=6,  text= "2.    VVI",bg='white', fg='black', border=1,command=VVI).place(x=300,y=100) #input button

            button4 = Button(window,width=20, pady=6,  text= "3.    VOO",bg='white', fg='black', border=1,command=VOO).place(x=300,y=160) #input button

            button5 = Button(window,width=20, pady=6, text= "4.     AAI",bg='white', fg='black', border=1,command=AAI).place(x=300,y=220) #input button
            
            button6 = Button(window,width=20, pady=6, text= "5.     AOOR",bg='white', fg='black', border=1,command=AOOR).place(x=460,y=40) #input button
            button7 = Button(window,width=20, pady=6, text= "6.     VOOR",bg='white', fg='black', border=1,command=VOOR).place(x=460,y=100) #input button       
            button8 = Button(window,width=20, pady=6, text= "7.     AAIR",bg='white', fg='black', border=1,command=AAIR).place(x=460,y=160) #input button
            button9 = Button(window,width=20, pady=6, text= "8.     VVIR",bg='white', fg='black', border=1,command=VVIR).place(x=460,y=220) #input button
            Button(window, width=20, pady=2, text="Logout",bg='black', fg='white', border=1, command=window.destroy).place(x=400, y=280) #button to close the window
            Label(window, text = "Pacemaker User:  %s" % (username),font = ("Calibri", 13)).pack(side = LEFT )
            Label(window, text = "CONNECTED TO PACEMAKER",fg = 'green' ,font = 'Helvetica 9 bold').pack(side = RIGHT)

            master.destroy()

            
            window.mainloop()
        

        def DISPLAY():
            global LOWER_RATE_LIMIT
            global UPPER_RATE_LIMIT
            global B_AMPLITUDE
            global PULSE_WIDTH
            global ARP_VRP
            
            global atrSENS
            global Hyster
            global rateSmoot
            global PVARp

            
            
            LOWER_RATE_LIMIT = list.get()
            B_AMPLITUDE = list1.get()
            PULSE_WIDTH = list2.get()
            ARP_VRP = list3.get()
            atrSENS = list4.get()
            Hyster=list5.get()
            SET_VALS()
            Label(master, text = "Your values have been saved", font = ("Calibri", 13)).place(x=470,y=680)            # print("_____________________________________")
            # print("The values for AAI :")
            # print("LOWER RATE LIMIT : ",LOWER_RATE_LIMIT)
            # print("UPPER RATE LIMIT : ", UPPER_RATE_LIMIT.get()) 
            # print("ATRIAL AMPLITUDE : ",B_AMPLITUDE)
            # print("ATRIAL PULSE WIDTH : ",PULSE_WIDTH)
            # print(" ARP : ",ARP_VRP)
            # print("ATRIAL SENSITIVITY : ", atrSENS) 
            # print("HYSTERESIS : ",Hyster)
            # print("RATESMOOTHING: ",rateSmoot.get())
            # print("RATESMOOTHING: ",PVARp.get())
            # print("_____________________________________") 
        Button(master, text = "Save", width="3", height = "1", command = DISPLAY).pack()
        Button(master, text = "Load", width="3", height = "1", command = ACCESS_LOAD).pack()
        Button(master, text="ECG", command=ECG).pack() #button to close the window

        Button(master, text="Back", command=connect2).pack() #button to close the window
        

        Label(master, text = "Pacemaker User:  %s" % (username),font = ("Calibri", 13)).pack(side = LEFT )

        Label(master, text = "").pack()
       
    ###############################################################
############################################################## 
# 
# 
# 
#    
        
    def VVI(): #function when button is clicked   
        window.destroy()
        global SET_CURRENT_MODE
        SET_CURRENT_MODE = 'VVI'
        global master
        master = Tk()
        master.geometry("900x700+300+100")
        master.title("VVI")
        global LOWER_RATE_LIMIT
        global UPPER_RATE_LIMIT
        global B_AMPLITUDE 
        global PULSE_WIDTH
        global ARP_VRP
        global VentSENS
        global Hyster
        global rateSmoot

        Label(master, text = "SET VALUES BELOW", font = ("Calibri", 13)).pack()
        Label(master, text = "").pack()








        Label(master, text = "Lower Rate Limit (ppm)").pack()
        CHOICES = [
            "30","35","40","45","50","51","52","53","54","55","56","57","58","59","60","61","62","63","64","65","66","67","68","69","70",
            "70","71","72","73","74","75","76","77","78","79","80","81","82","83","84","85","86","87","88","89",
            "90","95","105","110","115","120","125","130","135","140","145","150","155","160","165","170","175",
        ]
        choice = DoubleVar()
        choice.set(CHOICES[0])
        list = ttk.Combobox(master, value= CHOICES)
        list.current(14)
        list.bind("<<ComboboxSelected>>")
        list.pack() 
        Label(master, text = "").pack()







        Label(master, text = "Upper Rate Limit (ppm)").pack()
        UPPER_RATE_LIMIT = Scale(master, from_=50, to =175, resolution=5, orient=HORIZONTAL)
        UPPER_RATE_LIMIT.set(120)

        UPPER_RATE_LIMIT.pack()
        Label(master, text = "").pack()






        Label(master, text = "Ventricular Amplitude (V)").pack()
        CHOICES1 = [
        "0","0.1","0.2","0.3","0.4","0.5","0.6","0.7","0.8","0.9","1.0","1.1","1.2","1.3","1.4","1.5","1.6",
        "1.7","1.8","1.9","2.0","2.1","2.2","2.3","2.4","2.5","2.6","2.7","2.8","2.9","3.0","3.1","3.2","3.3",
        "3.4","3.5","3.6","3.7","3.8","3.9","4.0","4.1","4.2","4.3","4.4","4.5","4.6","4.7","4.8","4.9","5.0"
    ]
        choice1 = DoubleVar()
        choice1.set(CHOICES1[0])
        list1 = ttk.Combobox(master, value= CHOICES1)
        list1.current(29)
        list1.bind("<<ComboboxSelected>>")
        list1.pack()
        Label(master, text = "").pack()









        Label(master, text = "Ventricular Pulse Width (ms)").pack()
        CHOICES2 = [
        "1","2","3","4","5","6","7","8","9","10", "11","12","13","14","15","16","17","18","19","20", "21","22","23","24","25","26","27","28","29","30"
    ]
        choice2 = DoubleVar()
        choice2.set(CHOICES2[0])
        list2 = ttk.Combobox(master, value= CHOICES2)
        list2.current(4)
        list2.bind("<<ComboboxSelected>>")
        list2.pack()
        Label(master, text = "").pack()
        




        Label(master, text = "VRP(ms)").pack()
        CHOICES3 = [
            "150","160","170","180","190","200","210","220","230","240","250","260","270","280","290","300","310","320","330","340","350","360","370","380","390","400","410","420","430","440","450","460","470","480","490","500",
        ]
        choice3 = DoubleVar()
        choice3.set(CHOICES3[0])
        list3 = ttk.Combobox(master, value= CHOICES3)
        list3.current(17)
        list3.bind("<<ComboboxSelected>>")
        list3.pack()
        Label(master, text = "").pack()
        
        




        
        
        Label(master, text = "Ventricular sensistivity").pack()
        CHOICES4 = [
        "0","0.1","0.2","0.3","0.4","0.5","0.6","0.7","0.8","0.9","1.0","1.1","1.2","1.3","1.4","1.5","1.6",
        "1.7","1.8","1.9","2.0","2.1","2.2","2.3","2.4","2.5","2.6","2.7","2.8","2.9","3.0","3.1","3.2","3.3",
        "3.4","3.5","3.6","3.7","3.8","3.9","4.0","4.1","4.2","4.3","4.4","4.5","4.6","4.7","4.8","4.9","5.0"
    ]
        choice4 = DoubleVar()
        choice4.set(CHOICES4[0])
        list4 = ttk.Combobox(master, value= CHOICES4)
        list4.current(6)
        list4.bind("<<ComboboxSelected>>")
        list4.pack()
        Label(master, text = "").pack()
          
            



        Label(master, text = "Hystereisis").pack()
        CHOICES5 = ["OFF","Same as LRL"]
        choice5 = DoubleVar()
        choice5.set(CHOICES5[0])
        list5 = ttk.Combobox(master, value= CHOICES5)
        list5.current(0)
        list5.bind("<<ComboboxSelected>>")
        list5.pack()
        Label(master, text = "").pack() 
        
        






        Label(master, text = "Rate smoothing").pack()
        rateSmoot = Scale(master, from_=0, to =25,resolution=3.07, orient=HORIZONTAL)
        rateSmoot.set(0)
        rateSmoot.pack()
        Label(master, text = "").pack()


        def connect2():  #function for back button (reopen modes window)
            global window
            window = Tk()
            window.geometry('925x320+300+150')
            
            Label(window, text = "Please select your mode:", font = ("Calibri", 13)).place(x=400,y=10)

        #############################################BUTTONS FOR MODES

            button2 = Button(window,width=20, pady=6,  text= "1.    AOO",bg='white', fg='black', border=1,command=AOO).place(x=300,y=40) #input button
            
            button3 = Button(window,width=20, pady=6,  text= "2.    VVI",bg='white', fg='black', border=1,command=VVI).place(x=300,y=100) #input button

            button4 = Button(window,width=20, pady=6,  text= "3.    VOO",bg='white', fg='black', border=1,command=VOO).place(x=300,y=160) #input button

            button5 = Button(window,width=20, pady=6, text= "4.     AAI",bg='white', fg='black', border=1,command=AAI).place(x=300,y=220) #input button
            
            button6 = Button(window,width=20, pady=6, text= "5.     AOOR",bg='white', fg='black', border=1,command=AOOR).place(x=460,y=40) #input button
            button7 = Button(window,width=20, pady=6, text= "6.     VOOR",bg='white', fg='black', border=1,command=VOOR).place(x=460,y=100) #input button       
            button8 = Button(window,width=20, pady=6, text= "7.     AAIR",bg='white', fg='black', border=1,command=AAIR).place(x=460,y=160) #input button
            button9 = Button(window,width=20, pady=6, text= "8.     VVIR",bg='white', fg='black', border=1,command=VVIR).place(x=460,y=220) #input button
            Button(window, width=20, pady=2, text="Logout",bg='black', fg='white', border=1, command=window.destroy).place(x=400, y=280) #button to close the window
            Label(window, text = "Pacemaker User:  %s" % (username),font = ("Calibri", 13)).pack(side = LEFT )
            Label(window, text = "CONNECTED TO PACEMAKER",fg = 'green' ,font = 'Helvetica 9 bold').pack(side = RIGHT)

            master.destroy()

            
            window.mainloop()
        

        def DISPLAY():
            global LOWER_RATE_LIMIT
            global UPPER_RATE_LIMIT
            global B_AMPLITUDE 
            global PULSE_WIDTH
            global ARP_VRP
            global VentSENS
            global Hyster
            global rateSmoot
            LOWER_RATE_LIMIT = list.get()
            B_AMPLITUDE = list1.get()
            PULSE_WIDTH = list2.get()
            ARP_VRP = list3.get()
            VentSENS = list4.get()
            Hyster=list5.get()
            SET_VALS()          
            Label(master, text = "Your values have been saved", font = ("Calibri", 13)).place(x=500,y=600)            # print("_____________________________________")
            # print("The values for VVI :")
            # print("LOWER RATE LIMIT : ",LOWER_RATE_LIMIT)
            # print("UPPER RATE LIMIT : ", UPPER_RATE_LIMIT.get()) 
            # print("VENT AMPLITUDE : ",B_AMPLITUDE)
            # print("VENT PULSE WIDTH : ",PULSE_WIDTH)
            # print(" VRP : ",ARP_VRP)
            # print("VENT SENSITIVITY : ", VentSENS) 
            # print("HYSTERESIS : ",Hyster)
            # print("RATESMOOTHING: ",rateSmoot.get())
            # print("_____________________________________")            
        Button(master, text = "Save", width="3", height = "1", command = DISPLAY).pack()
        Button(master, text = "Load", width="3", height = "1", command = ACCESS_LOAD).pack()
        Button(master, text="ECG", command=ECG).pack() #button to close the window

        Button(master, text="Back", command=connect2).pack() #button to close the window
        Label(master, text = "Pacemaker User:  %s" % (username),font = ("Calibri", 13)).pack(side = LEFT )

        Label(master, text = "").pack()
        
        
    def AOOR(): #function when button is clicked  
        window.destroy() ### 
        global SET_CURRENT_MODE
        SET_CURRENT_MODE = 'AOOR'
        global master
        master = Tk()
        master.geometry("900x800+300+100")
        master.title("AOOR")
        global LOWER_RATE_LIMIT
        global UPPER_RATE_LIMIT
        global Max_Sensor_Rate
        global B_AMPLITUDE
        global PULSE_WIDTH
        global ATR_TH
        global REACTION_T
        global RESPONSE_F
        global RECOVERY_T

        Label(master, text = "SET VALUES BELOW", font = ("Calibri", 13)).pack()
        Label(master, text = "").pack()

        Label(master, text = "Lower Rate Limit (ppm)").pack()
        CHOICES = [
            "30","35","40","45","50","51","52","53","54","55","56","57","58","59","60","61","62","63","64","65","66","67","68","69","70",
            "70","71","72","73","74","75","76","77","78","79","80","81","82","83","84","85","86","87","88","89",
            "90","95","105","110","115","120","125","130","135","140","145","150","155","160","165","170","175",
        ]
        choice = DoubleVar()
        choice.set(CHOICES[0])
        list = ttk.Combobox(master, value= CHOICES)
        list.current(14)
        list.bind("<<ComboboxSelected>>")
        list.pack() 
        Label(master, text = "").pack()


        Label(master, text = "Upper Rate Limit (ppm)").pack()
        UPPER_RATE_LIMIT = Scale(master, from_=50, to =175, resolution=5, orient=HORIZONTAL)
        UPPER_RATE_LIMIT.set(120)

        UPPER_RATE_LIMIT.pack()
        Label(master, text = "").pack()
        
        Label(master, text = "Maximum Sensor Rate (ppm)").pack()
        Max_Sensor_Rate = Scale(master, from_=50, to =175, resolution=5, orient=HORIZONTAL)
        Max_Sensor_Rate.set(120)

        Max_Sensor_Rate.pack()
        Label(master, text = "").pack()

        Label(master, text = "Atrial Amplitude (V)").pack()
        CHOICES1 = [
            "0","0.1","0.2","0.3","0.4","0.5","0.6","0.7","0.8","0.9","1.0","1.1","1.2","1.3","1.4","1.5","1.6","1.7","1.8","1.9","2.0",
            "2.1","2.2","2.3","2.4","2.5","2.6","2.7","2.8","2.9","3.0","3.1","3.2","3.3","3.4","3.5","3.6","3.7","3.8","3.9","4.0","4.1","4.2","4.3","4.4","4.5","4.6","4.7","4.8","4.9","5.0",
        ]
        choice1 = DoubleVar()
        choice1.set(CHOICES1[0])
        list1 = ttk.Combobox(master, value= CHOICES1)
        list1.current(29)
        list1.bind("<<ComboboxSelected>>")
        list1.pack()
        Label(master, text = "").pack()



        Label(master, text = "Atrial Pulse Width (ms)").pack()
        CHOICES2 = [
            "0.05","0.1","0.2","0.3","0.4","0.5","0.6","0.7","0.8","0.9","1.0","1.1","1.2","1.3","1.4","1.5","1.6","1.7","1.8","1.9",
        ]
        choice2 = DoubleVar()
        choice2.set(CHOICES2[0])
        list2 = ttk.Combobox(master, value= CHOICES2)
        list2.current(4)
        list2.bind("<<ComboboxSelected>>")
        list2.pack()
        Label(master, text = "").pack()
        

        Label(master, text = "Activity Threshold").pack()
        CHOICES3 = ["V-Low","Low","Med-Low","Med","Med-High","High","V-High"]
        choice3 = DoubleVar()
        choice3.set(CHOICES3[0])
        list3 = ttk.Combobox(master, value= CHOICES3)
        list3.current(0)
        list3.bind("<<ComboboxSelected>>")
        list3.pack()
        Label(master, text = "").pack() 
        
        Label(master, text = "Reaction Time (s)").pack()
        Reaction_Time = Scale(master, from_=10, to =50, resolution=10, orient=HORIZONTAL)
        Reaction_Time.set(120)

        Reaction_Time.pack()
        Label(master, text = "").pack()

        
        Label(master, text = "Response Factor (min)").pack()
        Response_Factor = Scale(master, from_=1, to =16, resolution=1, orient=HORIZONTAL)
        Response_Factor.set(120)

        Response_Factor.pack()
        Label(master, text = "").pack()


        Label(master, text = "Recovery Time (min)").pack()
        Response_time = Scale(master, from_=2, to =16, resolution=1, orient=HORIZONTAL)
        Response_time.set(120)
        Response_time.pack()
        Label(master, text = "").pack()
        def connect2():
            global window
            window = Tk()
            window.geometry('925x320+300+150')
            
            Label(window, text = "Please select your mode:", font = ("Calibri", 13)).place(x=400,y=10)

        #############################################BUTTONS FOR MODES

            button2 = Button(window,width=20, pady=6,  text= "1.    AOO",bg='white', fg='black', border=1,command=AOO).place(x=300,y=40) #input button
            
            button3 = Button(window,width=20, pady=6,  text= "2.    VVI",bg='white', fg='black', border=1,command=VVI).place(x=300,y=100) #input button

            button4 = Button(window,width=20, pady=6,  text= "3.    VOO",bg='white', fg='black', border=1,command=VOO).place(x=300,y=160) #input button

            button5 = Button(window,width=20, pady=6, text= "4.     AAI",bg='white', fg='black', border=1,command=AAI).place(x=300,y=220) #input button
            
            button6 = Button(window,width=20, pady=6, text= "5.     AOOR",bg='white', fg='black', border=1,command=AOOR).place(x=460,y=40) #input button
            button7 = Button(window,width=20, pady=6, text= "6.     VOOR",bg='white', fg='black', border=1,command=VOOR).place(x=460,y=100) #input button       
            button8 = Button(window,width=20, pady=6, text= "7.     AAIR",bg='white', fg='black', border=1,command=AAIR).place(x=460,y=160) #input button
            button9 = Button(window,width=20, pady=6, text= "8.     VVIR",bg='white', fg='black', border=1,command=VVIR).place(x=460,y=220) #input button
            Button(window, width=20, pady=2, text="Logout",bg='black', fg='white', border=1, command=window.destroy).place(x=400, y=280) #button to close the window
            Label(window, text = "Pacemaker User:  %s" % (username),font = ("Calibri", 13)).pack(side = LEFT )
            Label(window, text = "CONNECTED TO PACEMAKER",fg = 'green' ,font = 'Helvetica 9 bold').pack(side = RIGHT)

            master.destroy()

            
            window.mainloop()
        
        
        def DISPLAY():
            global LOWER_RATE_LIMIT
            global UPPER_RATE_LIMIT
            global Max_Sensor_Rate
            global B_AMPLITUDE
            global PULSE_WIDTH
            global ATR_TH
            global REACTION_T
            global RESPONSE_F
            global RECOVERY_T
            
            
            LOWER_RATE_LIMIT = list.get()
            B_AMPLITUDE = list1.get()
            PULSE_WIDTH = list2.get()
            ATR_TH = list3.get()
            

            SET_VALS()
            Label(master, text = "Your values have been saved", font = ("Calibri", 13)).place(x=480,y=720)
          
        Button(master, text = "Save", width="3", height = "1", command = DISPLAY).pack()
        Button(master, text = "Load", width="3", height = "1", command = ACCESS_LOAD).pack()
        Button(master, text="Back", command=connect2).pack() #button to close the window
        Label(master, text = "Pacemaker User:  %s" % (username),font = ("Calibri", 13)).pack(side = LEFT )
        Label(master, text = "").pack()



        
    def VOOR(): #function when button is clicked   
        window.destroy()
        global SET_CURRENT_MODE
        SET_CURRENT_MODE = 'AOOR'
        global master
        master = Tk()
        master.geometry("900x800+300+100")
        master.title("VOOR")
        global LOWER_RATE_LIMIT
        global UPPER_RATE_LIMIT
        global Max_Sensor_Rate
        global B_AMPLITUDE
        global PULSE_WIDTH
        global ATR_TH
        global REACTION_T
        global RESPONSE_F
        global RECOVERY_T

        Label(master, text = "SET VALUES BELOW", font = ("Calibri", 13)).pack()
        Label(master, text = "").pack()

        Label(master, text = "Lower Rate Limit (ppm)").pack()
        CHOICES = [
            "30","35","40","45","50","51","52","53","54","55","56","57","58","59","60","61","62","63","64","65","66","67","68","69","70",
            "70","71","72","73","74","75","76","77","78","79","80","81","82","83","84","85","86","87","88","89",
            "90","95","105","110","115","120","125","130","135","140","145","150","155","160","165","170","175",
        ]
        choice = DoubleVar()
        choice.set(CHOICES[0])
        list = ttk.Combobox(master, value= CHOICES)
        list.current(14)
        list.bind("<<ComboboxSelected>>")
        list.pack() 
        Label(master, text = "").pack()


        Label(master, text = "Upper Rate Limit (ppm)").pack()
        UPPER_RATE_LIMIT = Scale(master, from_=50, to =175, resolution=5, orient=HORIZONTAL)
        UPPER_RATE_LIMIT.set(120)

        UPPER_RATE_LIMIT.pack()
        Label(master, text = "").pack()
        
        Label(master, text = "Maximum Sensor Rate (ppm)").pack()
        Max_Sensor_Rate = Scale(master, from_=50, to =175, resolution=5, orient=HORIZONTAL)
        Max_Sensor_Rate.set(120)

        Max_Sensor_Rate.pack()
        Label(master, text = "").pack()
        Label(master, text = "Ventricular Amplitude (V)").pack()
        CHOICES1 = [
            "0","0.5","0.6","0.7","0.8","0.9","1.0","1.1","1.2","1.3","1.4","1.5","1.6","1.7","1.8","1.9","2.0",
            "2.1","2.2","2.3","2.4","2.5","2.6","2.7","2.8","2.9","3.0","3.1","3.2","3.5","4.0","4.5","5.0","5.5",
            "6.0","6.5","7.0","7.5",
        ]
        choice1 = DoubleVar()
        choice1.set(CHOICES1[0])
        list1 = ttk.Combobox(master, value= CHOICES1)
        list1.current(29)
        list1.bind("<<ComboboxSelected>>")
        list1.pack()
        Label(master, text = "").pack()





        Label(master, text = "Ventricular Pulse Width (ms)").pack()
        CHOICES2 = [
            "0.05","0.1","0.2","0.3","0.4","0.5","0.6","0.7","0.8","0.9","1.0","1.1","1.2","1.3","1.4","1.5","1.6","1.7","1.8","1.9",
        ]
        choice2 = DoubleVar()
        choice2.set(CHOICES2[0])
        list2 = ttk.Combobox(master, value= CHOICES2)
        list2.current(4)
        list2.bind("<<ComboboxSelected>>")
        list2.pack()
        Label(master, text = "").pack()
        

        Label(master, text = "Activity Threshold").pack()
        CHOICES3 = ["V-Low","Low","Med-Low","Med","Med-High","High","V-High"]
        choice3 = DoubleVar()
        choice3.set(CHOICES3[0])
        list3 = ttk.Combobox(master, value= CHOICES3)
        list3.current(0)
        list3.bind("<<ComboboxSelected>>")
        list3.pack()
        Label(master, text = "").pack() 
        
        Label(master, text = "Reaction Time (s)").pack()
        Reaction_Time = Scale(master, from_=10, to =50, resolution=10, orient=HORIZONTAL)
        Reaction_Time.set(120)

        Reaction_Time.pack()
        Label(master, text = "").pack()

        
        Label(master, text = "Response Factor (min)").pack()
        Response_Factor = Scale(master, from_=1, to =16, resolution=1, orient=HORIZONTAL)
        Response_Factor.set(120)

        Response_Factor.pack()
        Label(master, text = "").pack()


        Label(master, text = "Recovery Time (min)").pack()
        Response_time = Scale(master, from_=2, to =16, resolution=1, orient=HORIZONTAL)
        Response_time.set(120)
        Response_time.pack()
        Label(master, text = "").pack()

        def connect2():
            global window
            window = Tk()
            window.geometry('925x320+300+150')
            
            Label(window, text = "Please select your mode:", font = ("Calibri", 13)).place(x=400,y=10)

        #############################################BUTTONS FOR MODES

            button2 = Button(window,width=20, pady=6,  text= "1.    AOO",bg='white', fg='black', border=1,command=AOO).place(x=300,y=40) #input button
            
            button3 = Button(window,width=20, pady=6,  text= "2.    VVI",bg='white', fg='black', border=1,command=VVI).place(x=300,y=100) #input button

            button4 = Button(window,width=20, pady=6,  text= "3.    VOO",bg='white', fg='black', border=1,command=VOO).place(x=300,y=160) #input button

            button5 = Button(window,width=20, pady=6, text= "4.     AAI",bg='white', fg='black', border=1,command=AAI).place(x=300,y=220) #input button
            
            button6 = Button(window,width=20, pady=6, text= "5.     AOOR",bg='white', fg='black', border=1,command=AOOR).place(x=460,y=40) #input button
            button7 = Button(window,width=20, pady=6, text= "6.     VOOR",bg='white', fg='black', border=1,command=VOOR).place(x=460,y=100) #input button       
            button8 = Button(window,width=20, pady=6, text= "7.     AAIR",bg='white', fg='black', border=1,command=AAIR).place(x=460,y=160) #input button
            button9 = Button(window,width=20, pady=6, text= "8.     VVIR",bg='white', fg='black', border=1,command=VVIR).place(x=460,y=220) #input button
            Button(window, width=20, pady=2, text="Logout",bg='black', fg='white', border=1, command=window.destroy).place(x=400, y=280) #button to close the window
            Label(window, text = "Pacemaker User:  %s" % (username),font = ("Calibri", 13)).pack(side = LEFT )
            Label(window, text = "CONNECTED TO PACEMAKER",fg = 'green' ,font = 'Helvetica 9 bold').pack(side = RIGHT)

            master.destroy()

            
            window.mainloop()
                
        def DISPLAY():
            global LOWER_RATE_LIMIT
            global UPPER_RATE_LIMIT
            global Max_Sensor_Rate
            global B_AMPLITUDE
            global PULSE_WIDTH
            global ATR_TH
            global REACTION_T
            global RESPONSE_F
            global RECOVERY_T
            
            
            LOWER_RATE_LIMIT = list.get()
            B_AMPLITUDE = list1.get()
            PULSE_WIDTH = list2.get()
            ATR_TH = list3.get()
            

            SET_VALS()
            Label(master, text = "Your values have been saved", font = ("Calibri", 13)).place(x=480,y=720)
          
        Button(master, text = "Save", width="3", height = "1", command = DISPLAY).pack()
        Button(master, text = "Load", width="3", height = "1", command = ACCESS_LOAD).pack()
        Button(master, text="Back", command=connect2).pack() #button to close the window
        Label(master, text = "Pacemaker User:  %s" % (username),font = ("Calibri", 13)).pack(side = LEFT )
        Label(master, text = "").pack()



        
    def AAIR(): #function when button is clicked   
        window.destroy()
        global SET_CURRENT_MODE
        SET_CURRENT_MODE = 'AAIR'
        global master
        master = Tk()
        master.geometry("700x600+300+100")
        master.title("AAIR")
        global LOWER_RATE_LIMIT
        global UPPER_RATE_LIMIT
        global Max_Sensor_Rate
        global B_AMPLITUDE
        global PULSE_WIDTH
        global ATR_TH
        global REACTION_T
        global RESPONSE_F
        global RECOVERY_T

        Label(master, text = "SET VALUES BELOW", font = ("Calibri", 13)).pack()
        

        Label(master, text = "Lower Rate Limit (ppm)").place(x=200,y=40)
        CHOICES = [
            "30","35","40","45","50","51","52","53","54","55","56","57","58","59","60","61","62","63","64","65","66","67","68","69","70",
            "70","71","72","73","74","75","76","77","78","79","80","81","82","83","84","85","86","87","88","89",
            "90","95","105","110","115","120","125","130","135","140","145","150","155","160","165","170","175",
        ]
        choice = DoubleVar()
        choice.set(CHOICES[0])
        list = ttk.Combobox(master, value= CHOICES)
        list.current(14)
        list.bind("<<ComboboxSelected>>")
        list.place(x=200,y=60)
       


        Label(master, text = "Upper Rate Limit (ppm)").place(x=200,y=100)
        UPPER_RATE_LIMIT = Scale(master, from_=50, to =175, resolution=5, orient=HORIZONTAL)
        UPPER_RATE_LIMIT.set(120)
        UPPER_RATE_LIMIT.place(x=200,y=120)
        
        Label(master, text = "Maximum Sensor Rate (ppm)").place(x=200,y=160)
        Max_Sensor_Rate = Scale(master, from_=50, to =175, resolution=5, orient=HORIZONTAL)
        Max_Sensor_Rate.set(120)
        Max_Sensor_Rate.place(x=200,y=180)

       
        Label(master, text = "Atrial Amplitude (V)").place(x=200,y=220)
        CHOICES1 = [
            "0","0.5","0.6","0.7","0.8","0.9","1.0","1.1","1.2","1.3","1.4","1.5","1.6","1.7","1.8","1.9","2.0",
            "2.1","2.2","2.3","2.4","2.5","2.6","2.7","2.8","2.9","3.0","3.1","3.2","3.5","4.0","4.5","5.0","5.5",
            "6.0","6.5","7.0","7.5",
        ]
        choice1 = DoubleVar()
        choice1.set(CHOICES1[0])
        list1 = ttk.Combobox(master, value= CHOICES1)
        list1.current(29)
        list1.bind("<<ComboboxSelected>>")
        list1.place(x=200,y=240)

        
        Label(master, text = "Atrial Pulse Width (ms)").place(x=200,y=280)
        CHOICES2 = [
            "0.05","0.1","0.2","0.3","0.4","0.5","0.6","0.7","0.8","0.9","1.0","1.1","1.2","1.3","1.4","1.5","1.6","1.7","1.8","1.9",
        ]
        choice2 = DoubleVar()
        choice2.set(CHOICES2[4])
        list2 = ttk.Combobox(master, value= CHOICES2)
        list2.current(0)
        list2.bind("<<ComboboxSelected>>")
        list2.place(x=200,y=300)
        


        
        
        
        Label(master, text = "ARP(ms)").place(x=200,y=340)
        CHOICES3 = [
            "150","160","170","180","190","200","210","220","230","240","250","260","270","280","290","300","310","320","330","340","350","360","370","380","390","400","410","420","430","440","450","460","470","480","490","500",
        ]
        choice3 = DoubleVar()
        choice3.set(CHOICES3[0])
        list3 = ttk.Combobox(master, value= CHOICES3)
        list3.current(17)
        list3.bind("<<ComboboxSelected>>")
        list3.place(x=200,y=360)
        
        
        
        Label(master, text = "Atrial sensistivity").place(x=200,y=400)
        CHOICES4 = [
            "0.25","0.5","0.75","1","1.5","2","2.5","3","3.5","4","4.5","5","5.5","6","6.5","7","7.5","8","8.5","9","9.5","10"]
        choice4 = DoubleVar()
        choice4.set(CHOICES4[0])
        list4 = ttk.Combobox(master, value= CHOICES4)
        list4.current(2)
        list4.bind("<<ComboboxSelected>>")
        list4.place(x=200,y=420)
        



        Label(master, text = "PVARP").place(x=400,y=100)
        PVARp = Scale(master, from_=150, to =500,resolution=10, orient=HORIZONTAL)
        PVARp.set(250)
        PVARp.place(x=400,y=120)
        
        

        Label(master, text = "Activity Threshold").place(x=400,y=40)
        CHOICES3 = ["V-Low","Low","Med-Low","Med","Med-High","High","V-High"]
        choice3 = DoubleVar()
        choice3.set(CHOICES3[0])
        list6 = ttk.Combobox(master, value= CHOICES3)
        list6.current(0)
        list6.bind("<<ComboboxSelected>>")
        list6.place(x=400,y=60)
        
        Label(master, text = "Reaction Time (s)").place(x=400,y=160)
        Reaction_Time = Scale(master, from_=10, to =50, resolution=10, orient=HORIZONTAL)
        Reaction_Time.set(120)
        Reaction_Time.place(x=400,y=180)

        
        Label(master, text = "Response Factor (min)").place(x=400,y=220)
        Response_Factor = Scale(master, from_=1, to =16, resolution=1, orient=HORIZONTAL)
        Response_Factor.set(120)
        Response_Factor.place(x=400,y=240)


        Label(master, text = "Recovery Time (min)").place(x=400,y=280)
        Response_time = Scale(master, from_=2, to =16, resolution=1, orient=HORIZONTAL)
        Response_time.set(120)
        Response_time.place(x=400,y=300)
        def connect2():
            global window
            window = Tk()
            window.geometry('925x320+300+150')
            
            Label(window, text = "Please select your mode:", font = ("Calibri", 13)).place(x=400,y=10)

        #############################################BUTTONS FOR MODES

            button2 = Button(window,width=20, pady=6,  text= "1.    AOO",bg='white', fg='black', border=1,command=AOO).place(x=300,y=40) #input button
            
            button3 = Button(window,width=20, pady=6,  text= "2.    VVI",bg='white', fg='black', border=1,command=VVI).place(x=300,y=100) #input button

            button4 = Button(window,width=20, pady=6,  text= "3.    VOO",bg='white', fg='black', border=1,command=VOO).place(x=300,y=160) #input button

            button5 = Button(window,width=20, pady=6, text= "4.     AAI",bg='white', fg='black', border=1,command=AAI).place(x=300,y=220) #input button
            
            button6 = Button(window,width=20, pady=6, text= "5.     AOOR",bg='white', fg='black', border=1,command=AOOR).place(x=460,y=40) #input button
            button7 = Button(window,width=20, pady=6, text= "6.     VOOR",bg='white', fg='black', border=1,command=VOOR).place(x=460,y=100) #input button       
            button8 = Button(window,width=20, pady=6, text= "7.     AAIR",bg='white', fg='black', border=1,command=AAIR).place(x=460,y=160) #input button
            button9 = Button(window,width=20, pady=6, text= "8.     VVIR",bg='white', fg='black', border=1,command=VVIR).place(x=460,y=220) #input button
            Button(window, width=20, pady=2, text="Logout",bg='black', fg='white', border=1, command=window.destroy).place(x=400, y=280) #button to close the window
            Label(window, text = "Pacemaker User:  %s" % (username),font = ("Calibri", 13)).pack(side = LEFT )
            Label(window, text = "CONNECTED TO PACEMAKER",fg = 'green' ,font = 'Helvetica 9 bold').pack(side = RIGHT)

            master.destroy()

            
            window.mainloop()
        
        
        def DISPLAY():
            global LOWER_RATE_LIMIT
            global UPPER_RATE_LIMIT
            global Max_Sensor_Rate
            global B_AMPLITUDE
            global PULSE_WIDTH
            global ATR_TH
            global REACTION_T
            global RESPONSE_F
            global RECOVERY_T
            
            
            LOWER_RATE_LIMIT = list.get()
            B_AMPLITUDE = list1.get()
            PULSE_WIDTH = list2.get()
            ATR_TH = list3.get()
            

            SET_VALS()
            Label(master, text = "Your values have been saved", font = ("Calibri", 13)).place(x=180,y=460)
          
        Button(master, text = "Save", width="3", height = "1", command = DISPLAY).place(x=400,y=360)
        Button(master, text = "Load", width="3", height = "1", command = ACCESS_LOAD).place(x=400,y=390)
        Button(master, text="Back", command=connect2).place(x=400,y=420) #button to close the window
        Label(master, text = "Pacemaker User:  %s" % (username),font = ("Calibri", 13)).pack(side = LEFT )
        Label(master, text = "").pack()




        
    def VVIR(): #function when button is clicked   
        window.destroy()
        global SET_CURRENT_MODE
        SET_CURRENT_MODE = 'VVIR'
        global master
        master = Tk()
        master.geometry("700x600+300+100")
        master.title("VVIR")
        global LOWER_RATE_LIMIT
        global UPPER_RATE_LIMIT
        global Max_Sensor_Rate
        global B_AMPLITUDE
        global PULSE_WIDTH
        global ATR_TH
        global REACTION_T
        global RESPONSE_F
        global RECOVERY_T

        Label(master, text = "SET VALUES BELOW", font = ("Calibri", 13)).pack()
        
        Label(master, text = "Lower Rate Limit (ppm)").place(x=200,y=40)
        CHOICES = [
            "30","35","40","45","50","51","52","53","54","55","56","57","58","59","60","61","62","63","64","65","66","67","68","69","70",
            "70","71","72","73","74","75","76","77","78","79","80","81","82","83","84","85","86","87","88","89",
            "90","95","105","110","115","120","125","130","135","140","145","150","155","160","165","170","175",
        ]
        choice = DoubleVar()
        choice.set(CHOICES[0])
        list = ttk.Combobox(master, value= CHOICES)
        list.current(14)
        list.bind("<<ComboboxSelected>>")
        list.place(x=200,y=60)
        


        Label(master, text = "Upper Rate Limit (ppm)").place(x=200,y=100)
        UPPER_RATE_LIMIT = Scale(master, from_=50, to =175, resolution=5, orient=HORIZONTAL)
        UPPER_RATE_LIMIT.set(120)
        UPPER_RATE_LIMIT.place(x=200,y=120)
     
        
        Label(master, text = "Maximum Sensor Rate (ppm)").place(x=200,y=160)
        Max_Sensor_Rate = Scale(master, from_=50, to =175, resolution=5, orient=HORIZONTAL)
        Max_Sensor_Rate.set(120)
        Max_Sensor_Rate.place(x=200,y=180)
  
        Label(master, text = "Ventricular Amplitude (V)").place(x=200,y=220)
        CHOICES1 = [
            "0","0.5","0.6","0.7","0.8","0.9","1.0","1.1","1.2","1.3","1.4","1.5","1.6","1.7","1.8","1.9","2.0",
            "2.1","2.2","2.3","2.4","2.5","2.6","2.7","2.8","2.9","3.0","3.1","3.2","3.5","4.0","4.5","5.0","5.5",
            "6.0","6.5","7.0","7.5",
        ]
        choice1 = DoubleVar()
        choice1.set(CHOICES1[0])
        list1 = ttk.Combobox(master, value= CHOICES1)
        list1.current(29)
        list1.bind("<<ComboboxSelected>>")
        list1.place(x=200,y=240)
      

        Label(master, text = "Ventricular Pulse Width (ms)").place(x=200,y=280)
        CHOICES2 = [
            "0.05","0.1","0.2","0.3","0.4","0.5","0.6","0.7","0.8","0.9","1.0","1.1","1.2","1.3","1.4","1.5","1.6","1.7","1.8","1.9",
        ]
        choice2 = DoubleVar()
        choice2.set(CHOICES2[0])
        list2 = ttk.Combobox(master, value= CHOICES2)
        list2.current(4)
        list2.bind("<<ComboboxSelected>>")
        list2.place(x=200,y=300)
      

        Label(master, text = "VRP(ms)").place(x=200,y=340)
        CHOICES3 = [
            "150","160","170","180","190","200","210","220","230","240","250","260","270","280","290","300","310","320","330","340","350","360","370","380","390","400","410","420","430","440","450","460","470","480","490","500",
        ]
        choice3 = DoubleVar()
        choice3.set(CHOICES3[0])
        list3 = ttk.Combobox(master, value= CHOICES3)
        list3.current(17)
        list3.bind("<<ComboboxSelected>>")
        list3.place(x=200,y=360)
  

        
        Label(master, text = "Ventricular sensistivity").place(x=200,y=400)
        CHOICES4 = [
            "0.25","0.5","0.75","1","1.5","2","2.5","3","3.5","4","4.5","5","5.5","6","6.5","7","7.5","8","8.5","9","9.5","10"]
        choice4 = DoubleVar()
        choice4.set(CHOICES4[0])
        list4 = ttk.Combobox(master, value= CHOICES4)
        list4.current(6)
        list4.bind("<<ComboboxSelected>>")
        list4.place(x=200,y=420)



        

        Label(master, text = "Activity Threshold").place(x=400,y=40)
        CHOICES6 = ["V-Low","Low","Med-Low","Med","Med-High","High","V-High"]
        choice6 = DoubleVar()
        choice6.set(CHOICES3[0])
        list6 = ttk.Combobox(master, value= CHOICES3)
        list6.current(0)
        list6.bind("<<ComboboxSelected>>")
        list6.place(x=400,y=60)
    
        
        Label(master, text = "Reaction Time (s)").place(x=400,y=100)
        Reaction_Time = Scale(master, from_=10, to =50, resolution=10, orient=HORIZONTAL)
        Reaction_Time.set(120)
        Reaction_Time.place(x=400,y=120)
        

        
        Label(master, text = "Response Factor (min)").place(x=400,y=160)
        Response_Factor = Scale(master, from_=1, to =16, resolution=1, orient=HORIZONTAL)
        Response_Factor.set(120)
        Response_Factor.place(x=400,y=180)
        


        Label(master, text = "Recovery Time (min)").place(x=400,y=220)
        Response_time = Scale(master, from_=2, to =16, resolution=1, orient=HORIZONTAL)
        Response_time.set(120)
        Response_time.place(x=400,y=240)
      
        def connect2():
            global window
            window = Tk()
            window.geometry('925x320+300+150')
            
            Label(window, text = "Please select your mode:", font = ("Calibri", 13)).place(x=400,y=10)

        #############################################BUTTONS FOR MODES

            button2 = Button(window,width=20, pady=6,  text= "1.    AOO",bg='white', fg='black', border=1,command=AOO).place(x=300,y=40) #input button
            
            button3 = Button(window,width=20, pady=6,  text= "2.    VVI",bg='white', fg='black', border=1,command=VVI).place(x=300,y=100) #input button

            button4 = Button(window,width=20, pady=6,  text= "3.    VOO",bg='white', fg='black', border=1,command=VOO).place(x=300,y=160) #input button

            button5 = Button(window,width=20, pady=6, text= "4.     AAI",bg='white', fg='black', border=1,command=AAI).place(x=300,y=220) #input button
            
            button6 = Button(window,width=20, pady=6, text= "5.     AOOR",bg='white', fg='black', border=1,command=AOOR).place(x=460,y=40) #input button
            button7 = Button(window,width=20, pady=6, text= "6.     VOOR",bg='white', fg='black', border=1,command=VOOR).place(x=460,y=100) #input button       
            button8 = Button(window,width=20, pady=6, text= "7.     AAIR",bg='white', fg='black', border=1,command=AAIR).place(x=460,y=160) #input button
            button9 = Button(window,width=20, pady=6, text= "8.     VVIR",bg='white', fg='black', border=1,command=VVIR).place(x=460,y=220) #input button
            Button(window, width=20, pady=2, text="Logout",bg='black', fg='white', border=1, command=window.destroy).place(x=400, y=280) #button to close the window
            Label(window, text = "Pacemaker User:  %s" % (username),font = ("Calibri", 13)).pack(side = LEFT )
            Label(window, text = "CONNECTED TO PACEMAKER",fg = 'green' ,font = 'Helvetica 9 bold').pack(side = RIGHT)
            window.mainloop()

            master.destroy()

            
        
        def DISPLAY():
            global LOWER_RATE_LIMIT
            global UPPER_RATE_LIMIT
            global Max_Sensor_Rate
            global B_AMPLITUDE
            global PULSE_WIDTH
            global ATR_TH
            global REACTION_T
            global RESPONSE_F
            global RECOVERY_T
            
            
            LOWER_RATE_LIMIT = list.get()
            B_AMPLITUDE = list1.get()
            PULSE_WIDTH = list2.get()
            ATR_TH = list3.get()
            

            SET_VALS()
            Label(master, text = "Your values have been saved", font = ("Calibri", 13)).place(x=180,y=460)
          
        Button(master, text = "Save", width="3", height = "1", command = DISPLAY).place(x=400,y=300)
        Button(master, text = "Load", width="3", height = "1", command = ACCESS_LOAD).place(x=400,y=330)
        Button(master, text="Back", command=connect2).place(x=400,y=360) #button to close the window
        Label(master, text = "Pacemaker User:  %s" % (username),font = ("Calibri", 13)).pack(side = LEFT )
        Label(master, text = "").pack()



  ###############################################################

           #                  CONNECT SCREEN + MODES                   

###############################################################  
    def ECG():
        y_axis = []
        for i in range(2000):
            ser.write(b'\x16'+b'\x22'+(struct.pack("B",0)*14))
            data = ser.read(22)
                
            y_axis.append(struct.unpack("f",data[14:18])[0])
            #print(struct.unpack("f",data[14:18])[0])
            #time.sleep(0.001)
            
        x_axis = []
        for i in range(2000):
            x_axis.append(i)

        plt.plot(x_axis, y_axis)
        plt.title('Pacemaker EGM Data')
        plt.xlabel('milliseconds (ms)')
        plt.ylabel('millivolts (mV)')
        plt.show()

        
    def connect():
        screen.destroy()
        
        
        # connected via UArt
        try:
            
            global ser
            ser = serial.Serial(serial_port, 115200)  # COM PORT CHANGE
            
            messagebox.showinfo('Success', 'You have been successfully connected!')
            global window
            window = Tk()
            window.geometry('925x320+300+150')
            
            Label(window, text = "Please select your mode:", font = ("Calibri", 13)).place(x=400,y=10)

        #############################################BUTTONS FOR MODES

            button2 = Button(window,width=20, pady=6,  text= "1.    AOO",bg='white', fg='black', border=1,command=AOO).place(x=300,y=40) #input button
            
            button3 = Button(window,width=20, pady=6,  text= "2.    VVI",bg='white', fg='black', border=1,command=VVI).place(x=300,y=100) #input button

            button4 = Button(window,width=20, pady=6,  text= "3.    VOO",bg='white', fg='black', border=1,command=VOO).place(x=300,y=160) #input button

            button5 = Button(window,width=20, pady=6, text= "4.     AAI",bg='white', fg='black', border=1,command=AAI).place(x=300,y=220) #input button
            
            button6 = Button(window,width=20, pady=6, text= "5.     AOOR",bg='white', fg='black', border=1,command=AOOR).place(x=460,y=40) #input button
            button7 = Button(window,width=20, pady=6, text= "6.     VOOR",bg='white', fg='black', border=1,command=VOOR).place(x=460,y=100) #input button       
            button8 = Button(window,width=20, pady=6, text= "7.     AAIR",bg='white', fg='black', border=1,command=AAIR).place(x=460,y=160) #input button
            button9 = Button(window,width=20, pady=6, text= "8.     VVIR",bg='white', fg='black', border=1,command=VVIR).place(x=460,y=220) #input button
            Button(window, width=20, pady=2, text="Logout",bg='black', fg='white', border=1, command=window.destroy).place(x=400, y=280) #button to close the window
            Label(window, text = "Pacemaker User:  %s" % (username),font = ("Calibri", 13)).pack(side = LEFT )
            Label(window, text = "CONNECTED TO PACEMAKER",fg = 'green' ,font = 'Helvetica 9 bold').pack(side = RIGHT)
            window.mainloop()
        except:
            messagebox.showerror('Error', 'Make sure to connect the pacemaker!')
                


       

##############################################CONNECT BUTTON          
    if username in r.keys() and password==r[username]:
        
        screen = Tk()
        screen.geometry('300x100+300+150')
       
        screen.title("Connect")
        screen.config(bg='white')
    
        label=Label(screen, text="Please click the button below to connect your device").pack() 
       
          
      
        button = Button(screen, text= "Connect") #input button
        button.config(command=connect)
        button.pack(side=TOP,padx=0,pady=0)
       
        
            
        
        frame = Frame(screen, width=350, height=350, bg='white')
        frame.place(x=250, y=100)
        
     

        screen.destroy
        modes = 'The modes';
      
    else:
        messagebox.showerror('Error', 'User not in system')

        mainloop()

###############################################################
###############################################################
    ###################




    # #REGISTRATION SYSTEM




    # ########################################### ###############################################################        
###############################################################
###############################################################
###############################################################
        ## SIGN UP POP-UP
def registerPopup():
    window=Toplevel(wind)
##--
    window.title("Register")
    window.geometry('925x500+300+150')
    window.configure(bg='#fff')
    window.resizable(False, False)

    Label(window, text='Register', fg='black', bg='white', font=('Microsoft YaHei UI', 24)).place(x=100, y=20)

    ## REGISTER
    def register():
        username = user.get()
        password = passw.get()
        passwordConfirm = passwConfirm.get()
        specialc = """#$%&'()*!+,-."/:;<=>?@[\]^_`{|}~"""""
        lengUser = len(username)
        lengPass = len(password)
        space = " "
        if password == passwordConfirm:

        

            try:
                file = open('LOGIN_DATA.txt', 'r+')
                d = file.read()
                r = ast.literal_eval(d)
                dict = {username: password}
                if any(c in space for c in password):
                    messagebox.showerror('Error', 'Space in password!')
                elif (username is None or lengUser ==0 or username =="username" or username == '' or username == ""):
                    messagebox.showerror('Error', 'EMPTY user!')
                elif (lengPass > 20):
                    messagebox.showerror('Error', 'more than 20 characters!')
                elif username in r.keys():
                    messagebox.showerror('Error', 'Username Already Exists!')
                elif (lengUser > 20):
                    messagebox.showerror('Error', 'more than 20 characters!')
                elif any(c in specialc for c in username):
                    messagebox.showerror('Error', 'Special in user!')
                else: 
                    if len(r) <= 10:
                        r.update(dict)
                        file.truncate(0)
                        file.close()
                        file = open('LOGIN_DATA.txt', 'w')
                        w = file.write(str(r))
                        messagebox.showinfo('Success', 'Registered Successfully!')
                        f = open("IMPORT.json", "r+")
                        data = json.load(f)
                        NEW_USER_DATA = {"username": f"{username}",
                                        "AOO": {
                                            "LOWER RL": "",
                                            "UPPER RL": "",
                                            "ATRIAL AMPLITUDE": "",
                                            "ATRIAL PW": ""
                                        },
                                        "AAI": {
                                            "LOWER RL": "",
                                            "UPPER RL": "",
                                            "ATRIAL AMPLITUDE": "",
                                            "ATRIAL PW": "",
                                            "ARP": "",
                                            "AS": "",
                                            "PVARP": "",
                                            "H": "",
                                            "S": ""
                                        },
                                        "VOO": {
                                            "LOWER RL": "",
                                            "UPPER RL": "",
                                            "VA": "",
                                            "VENTRICULAR PULSE WIDTH": ""
                                        },
                                        "VVI": {
                                            "LOWER RL": "",
                                            "UPPER RL": "",
                                            "VA": "",
                                            "VENTRICULAR PULSE WIDTH": "",
                                            "VRP": "",
                                            "VS": "",
                                            "H": "",
                                            "S": ""
                                        }}
                        data.append(NEW_USER_DATA)
                        f.seek(0)
                        json.dump(data, f, indent=4)
                        f.close()
                    else:
                        messagebox.showerror('Error', 'User Capacity Reached!')
            except:
                file = open('LOGIN_DATA.txt', 'w')
                pp = str({'Username': 'password'})
                file.write(pp)
                file.close()
                pp1=[{"username": " ",
                                    "AOO": {
                                        "LOWER RL": "",
                                        "UPPER RL": "",
                                        "ATRIAL AMPLITUDE": "",
                                        "ATRIAL PW": ""
                                    },
                                    "AAI": {
                                        "LOWER RL": "",
                                        "UPPER RL": "",
                                        "ATRIAL AMPLITUDE": "",
                                        "ATRIAL PW": "",
                                        "ARP": "",
                                        "AS": "",
                                        "PVARP": "",
                                        "H": "",
                                        "S": ""
                                    },
                                    "VOO": {
                                        "LOWER RL": "",
                                        "UPPER RL": "",
                                        "VA": "",
                                        "VENTRICULAR PULSE WIDTH": ""
                                    },
                                    "VVI": {
                                        "LOWER RL": "",
                                        "UPPER RL": "",
                                        "VA": "",
                                        "VENTRICULAR PULSE WIDTH": "",
                                        "VRP": "",
                                        "VS": "",
                                        "H": "",
                                        "S": ""
                                    }}]
                with open('IMPORT.json','w') as f:
                    json.dump(pp1,f,indent=4)
                f.close()
        else:
            messagebox.showerror('Error', 'Passwords do not match!')

#######################################################################################################################
###################  FIELDS TO ENTER IN REGISTER     ############################################
##############################################################
    ## USERNAME FIELD
    def Enter(e):
        user.delete(0, 'end')

    def Leave(e):
        if user.get() == '':
            user.insert(0, 'username')

    user = Entry(window, width=25, fg='black', border=0, bg='white', font=('Microsoft Yahei UI Light', 11))
    user.place(x=50, y=110)
    user.insert(0, 'username')
    user.bind("<FocusIn>", Enter)
    user.bind("<FocusOut>", Leave)
    Frame(window, width=250, height=2, bg='black').place(x=50, y=137)

    ## PASSWORD FIELD
    def Enter(e):
        passw.delete(0, 'end')

    def Leave(e):
        if passw.get() == '':
            passw.insert(0, 'password')

    passw = Entry(window, width=25, fg='black', border=0, bg='white', font=('Microsoft Yahei UI Light', 11))
    passw.place(x=50, y=170)
    passw.config(show='*')
    passw.insert(0, 'password')
    passw.bind("<FocusIn>", Enter)
    passw.bind("<FocusOut>", Leave)
    Frame(window, width=250, height=2, bg='black').place(x=50, y=197)

    ## CONFIRM PASSWORD FIELD
    def Enter(e):
        passwConfirm.delete(0, 'end')

    def Leave(e):
        if passwConfirm.get() == '':
            passwConfirm.insert(0, 'Confirm Password')

    passwConfirm = Entry(window, width=25, fg='black', border=0, bg='white', font=('Microsoft Yahei UI Light', 11))
    passwConfirm.place(x=50, y=230)
    passwConfirm.config(show='*')
    passwConfirm.insert(0, 'Confirm Password')
    passwConfirm.bind("<FocusIn>", Enter)
    passwConfirm.bind("<FocusOut>", Leave)
    Frame(window, width=250, height=2, bg='black').place(x=50, y=257)

    ## SIGN UP BUTTON
    Button(window, width=30, pady=8, text="Sign Up", bg='black', fg='white', border=0, command=register).place(x=70, y=310)

    window.mainloop()

#######################################################################################################################
###################  FIELDS TO ENTER IN SIGN IN    ############################################
##############################################################
## USERNAME BOX
def Enter(e):
    user.delete(0, 'end')

def Leave(e):
    if user.get() == '':
        user.insert(0, 'username')

user = Entry(frame, width=36, fg='black', border=0, bg='white', font=('Microsoft YaHei UI Light', 11))
user.place(x=75, y=80)
user.insert(0, 'username')
user.bind('<FocusIn>', Enter)
user.bind('<FocusOut>', Leave)
Frame(frame, width=295, height=2, bg='black').place(x=70, y=110)


## PASSWORD BOX
def BOXENTER1(e):
    passw.delete(0, 'end')

def BOXEXIT1(e):
    if passw.get() == '':
        passw.insert(0, 'password')

passw = Entry(frame, width=36, fg='black', border=0, bg='white', font=('Microsoft YaHei UI Light', 11))
passw.place(x=75, y=150)
passw.config(show='*')
passw.insert(0, 'password')
passw.bind('<FocusIn>', BOXENTER1)
passw.bind('<FocusOut>', BOXEXIT1)
Frame(frame, width=295, height=2, bg='black').place(x=70, y=180)

## SIGN IN BUTTON
Button(frame, width=30, pady=8, text='Sign in', bg='black', fg='white', border=0,command=signin).place(x=110, y=225)
# SIGN UP
Label(frame, text="Don't have an account ?", fg='black', bg='white', font=('Microsoft YaHei UI Light', 10)).place(x=120, y=265)
Button(frame, width=6, text='Sign up', border=0, bg='white', cursor='hand2', fg='#57a1f8',command=registerPopup).place(x=270,y=267)

###############################################################
###############################################################
    ###################




    # #SET VALUES FOR THE USER AFTER HE SAVES 




    # ########################################### ###############################################################        
###############################################################
###############################################################
###############################################################





def SET_VALS():

    #check mode 
    if SET_CURRENT_MODE=='AOO':
        
        AOO_LOWER_RATE= LOWER_RATE_LIMIT
        
        AOO_UPPER_RATE= str(UPPER_RATE_LIMIT.get())
        
        AOO_ATRIAL_AMP= B_AMPLITUDE
        
        AOO_ATRIAL_PW= PULSE_WIDTH
        
        #CHECK IF LOWER BIGGER THAN UPPER

        if int(LOWER_RATE_LIMIT) >= UPPER_RATE_LIMIT.get():
            messagebox.showwarning('ERROR','LowerRate cannot exceed UpperRate')
        else:
            
            
            
            f = open("IMPORT.json", "r+")
            
            data = json.load(f)
            ## add to json file 
            for INCREMENTED in data:
                if INCREMENTED["username"] == user.get():
                    INCREMENTED["AOO"]["LOWER RL"] = AOO_LOWER_RATE
                    INCREMENTED["AOO"]["UPPER RL"] = AOO_UPPER_RATE
                    INCREMENTED["AOO"]["ATRIAL AMPLITUDE"] = AOO_ATRIAL_AMP
                    INCREMENTED["AOO"]["ATRIAL PW"] = AOO_ATRIAL_PW
            open("IMPORT.json", "w").write(
                json.dumps(data, indent=4, separators=(',', ': '))
            )
    elif SET_CURRENT_MODE=='AAI':
        AAI_LOWER_RATE=LOWER_RATE_LIMIT
        
        AAI_UPPER_RATE=str(UPPER_RATE_LIMIT.get())
        
        AAI_ATRIAL_AMP=B_AMPLITUDE
        
        AAI_APW=PULSE_WIDTH
        
        AAI_ARP=ARP_VRP
        
        AAI_ATRIAL_SENSETIVITY= atrSENS
        
        AAI_PVARP= str(PVARp.get()) 
        
        AAI_HYSTERESIS= Hyster
        
        AAI_RATE_SMOOTHING= str(rateSmoot.get())


        
        if int(LOWER_RATE_LIMIT) >= UPPER_RATE_LIMIT.get():
            messagebox.showwarning('ERROR','LowerRate cannot exceed UpperRate')
        else:
          
            f = open("IMPORT.json", "r+")
            data = json.load(f)
            for INCREMENTED in data:
                if INCREMENTED["username"] == user.get():
                    INCREMENTED["AAI"]["LOWER RL"] = AAI_LOWER_RATE
                    INCREMENTED["AAI"]["UPPER RL"] = AAI_UPPER_RATE
                    INCREMENTED["AAI"]["ATRIAL AMPLITUDE"] = AAI_ATRIAL_AMP
                    INCREMENTED["AAI"]["ATRIAL PW"] = AAI_APW
                    INCREMENTED["AAI"]["ARP"] = AAI_ARP
                    INCREMENTED["AAI"]["AS"] = AAI_ATRIAL_SENSETIVITY
                    INCREMENTED["AAI"]["PVARP"] = AAI_PVARP
                    INCREMENTED["AAI"]["H"] = AAI_HYSTERESIS
                    INCREMENTED["AAI"]["S"] = AAI_RATE_SMOOTHING
            open("IMPORT.json", "w").write(
                json.dumps(data, indent=4, separators=(',', ': '))
            )
    elif SET_CURRENT_MODE=='VOO':
        VOO_LOWER_RATE=LOWER_RATE_LIMIT
        VOO_UPPER_RATE=str(UPPER_RATE_LIMIT.get())
        VOO_VENTRICUALAR_AMP=B_AMPLITUDE
        VOO_VENTRICULAR_PW=PULSE_WIDTH
        if int(LOWER_RATE_LIMIT) >= UPPER_RATE_LIMIT.get():
            messagebox.showwarning('ERROR','LowerRate cannot exceed UpperRate')
        else:
          
            f = open("IMPORT.json", "r+")
            data = json.load(f)
            for INCREMENTED in data:
                if INCREMENTED["username"] == user.get():
                    INCREMENTED["VOO"]["LOWER RL"] = VOO_LOWER_RATE
                    INCREMENTED["VOO"]["UPPER RL"] = VOO_UPPER_RATE
                    INCREMENTED["VOO"]["VA"] = VOO_VENTRICUALAR_AMP
                    INCREMENTED["VOO"]["VENTRICULAR PULSE WIDTH"] = VOO_VENTRICULAR_PW
            open("IMPORT.json", "w").write(
                json.dumps(data, indent=4, separators=(',', ': '))
            )
    elif SET_CURRENT_MODE=='VVI':
        
        VVI_LOWER_RATE=LOWER_RATE_LIMIT
        VVI_UPPER_RATE=str(UPPER_RATE_LIMIT.get())
        VVI_VENTRICAL_AMP= B_AMPLITUDE
        VVI_VENTRICAL_PW=PULSE_WIDTH
        VVI_VRP=ARP_VRP
        VVI_VENTRICULAR_SENSITIVITY=VentSENS
        VVI_HYSTEREISIS=Hyster
        VVI_RATE_SMOOTHINGS=str(rateSmoot.get())
        if int(LOWER_RATE_LIMIT) >= UPPER_RATE_LIMIT.get():
            messagebox.showwarning('ERROR','LowerRate cannot exceed UpperRate')
        else:
           
            f = open("IMPORT.json", "r+")
            data = json.load(f)
            for INCREMENTED in data:
                if INCREMENTED["username"] == user.get():
                    INCREMENTED["VVI"]["LOWER RL"] = VVI_LOWER_RATE
                    INCREMENTED["VVI"]["UPPER RL"] = VVI_UPPER_RATE
                    INCREMENTED["VVI"]["VA"] = VVI_VENTRICAL_AMP
                    INCREMENTED["VVI"]["VENTRICULAR PULSE WIDTH"] = VVI_VENTRICAL_PW
                    INCREMENTED["VVI"]["VRP"] = VVI_VRP
                    INCREMENTED["VVI"]["VS"] = VVI_VENTRICULAR_SENSITIVITY
                    INCREMENTED["VVI"]["H"] = VVI_HYSTEREISIS
                    INCREMENTED["VVI"]["S"] = VVI_RATE_SMOOTHINGS
            open("IMPORT.json", "w").write(
                json.dumps(data, indent=4, separators=(',', ': '))
            )

###############################################################
###############################################################
    ###################




    # #LOAD THE VALUES FOR THE USER AFTER HE REOPEN




    # ########################################### ###############################################################        
###############################################################
###############################################################
###############################################################



def ACCESS_LOAD():
    #check the mode 
    if SET_CURRENT_MODE=='VOO':
        f = open("IMPORT.json", "r+")
        data = json.load(f)
        for INCREMENTED in data:
            if INCREMENTED["username"] == user.get():
                #check if empty
                if INCREMENTED["VOO"]["UPPER RL"] == "":
                    print("Nothing to load, save parameters first")
                    print("USER:", user.get())
                else:
                    #iterate through to display in loaded 
                    VOO_LOWER_RATE = INCREMENTED["VOO"]["LOWER RL"]
                    VOO_UPPER_RATE = INCREMENTED["VOO"]["UPPER RL"]
                    VOO_VENTRICUALAR_AMP = INCREMENTED["VOO"]["VA"]
                    VOO_VENTRICULAR_PW = INCREMENTED["VOO"]["VENTRICULAR PULSE WIDTH"] 

                    def loaded():
                        
                        
                        
                        Label(window, text = ("Pacemaker User:", user.get()), font = ("Calibri", 13)).place(x=400,y=90)
                        Label(window, text =("LOWER RATE LIMIT:", VOO_LOWER_RATE), font = ("Calibri", 13)).place(x=400,y=130)
                        Label(window, text = ("UPPER RATE LIMIT:", VOO_UPPER_RATE), font = ("Calibri", 13)).place(x=400,y=170)
                        Label(window, text =("Vent AMPLITUDE:", VOO_VENTRICUALAR_AMP), font = ("Calibri", 13)).place(x=400,y=210)
                        Label(window, text =("Vent PULSE WIDTH:", VOO_VENTRICULAR_PW), font = ("Calibri", 13)).place(x=400,y=250)
                       
                        '''
                        print("________________________________________________________") 
                        print("PREVIOUS VALUES FOR VOO")
                        print("Pacemaker User:", user.get())
                        print("LOWER RATE LIMIT:", VOO_LOWER_RATE)
                        print("UPPER RATE LIMIT:", VOO_UPPER_RATE)
                        print("Vent AMPLITUDE:", VOO_VENTRICUALAR_AMP)
                        print("Vent PULSE WIDTH:", VOO_VENTRICULAR_PW) 
                        print("________________________________________________________") 
                        
                        '''

                        try:
                            time.sleep(0.5)

                            Pace_mode = 0 #0 - VTR, 1 - ATR
                            Sensing_control = 0 #0 - OFF, 1 - ON
                            Ventricle_amplitude = int(float(VOO_VENTRICUALAR_AMP)*10) #In *10 volts, so 3.5V
                            Atrial_amplitude = 0
                            Atrial_pace_width = 0
                            Ventricle_pace_width = int(float(VOO_VENTRICULAR_PW))
                            Atrial_rf_period = 0 #in ms (requires short)
                            Ventricle_rf_period = 0
                            Lower_rate_limit = int(VOO_LOWER_RATE) #in ms
                            Upper_rate_limit = int(VOO_UPPER_RATE)
                            Atrial_sensitivity = 0 #in *10 volts
                            Ventricle_sensitivity = 0



                            start_byte = b'\x16'
                            echo_byte = b'\x22'
                            set_byte = b'\x55'

                            Pace_Mode = struct.pack("B", Pace_mode)
                            Sensing_Control = struct.pack("B", Sensing_control)
                            Atrial_Amplitude = struct.pack("B",Atrial_amplitude )
                            Ventricle_Amplitude = struct.pack("B", Ventricle_amplitude)
                            Atrial_PaceWidth = struct.pack("B", Atrial_pace_width)
                            Ventricle_PaceWidth = struct.pack("B", Ventricle_pace_width)
                            Atrial_Refractory_Period = struct.pack("H", Atrial_rf_period)
                            Ventricle_Refractory_Period = struct.pack("H", Ventricle_rf_period)
                            LRL = struct.pack("B", Lower_rate_limit)
                            URL = struct.pack("B", Upper_rate_limit)
                            Atrial_Sensitivity = struct.pack("B", Atrial_sensitivity)
                            Ventricle_Sensitivity = struct.pack("B", Ventricle_sensitivity)


                            Signal_set = start_byte + set_byte + Pace_Mode + Sensing_Control + Atrial_Amplitude + Ventricle_Amplitude + Atrial_PaceWidth + Ventricle_PaceWidth + Atrial_Refractory_Period + Ventricle_Refractory_Period + LRL + URL + Atrial_Sensitivity + Ventricle_Sensitivity
                            Signal_echo = start_byte + echo_byte + Pace_Mode + Sensing_Control + Atrial_Amplitude + Ventricle_Amplitude + Atrial_PaceWidth + Ventricle_PaceWidth + Atrial_Refractory_Period + Ventricle_Refractory_Period + LRL + URL + Atrial_Sensitivity + Ventricle_Sensitivity
                                            
                            print("Params Being Sent...")
                            ser.write(Signal_set)


                            ser.write(Signal_echo)
                            print("running")
                            data = ser.read(14)
                            print("still running")
                            v1 = data[0]
                            v2 = data[1]
                            v3 = data[2]
                            v4 = data[3]
                            v5 = data[4]
                            v6 = data[5]
                            v7 = struct.unpack("H", data[6:8])[0]
                            v8 = struct.unpack("H", data[8:10])[0]
                            v9 = data[10]
                            v10 = data[11]
                            v11 = data[12]
                            v12 = data[13]
                            
                            

                            print("From the board:")
                            print("Pace_mode = ", v1)
                            print("Sensing_control = ", v2)
                            print("Atrial_Amplitude = ", v3)
                            print("Ventricle_Amplitude = ", v4)
                            print("Atrial_PaceWidth = ", v5)
                            print("Ventricle_PaceWidth = ", v6)
                            print("Atrial_Refractory_Period = ", v7)
                            print("Ventricle_Refractory_Period = ", v8)
                            print("LRL = ", v9)
                            print("URL = ", v10)
                            print("Atrial_Sensitivity = ", v11)
                            print("Ventricle_Sensitivity = ", v12)
                        except:
                            messagebox.showerror('Error', 'Make sure to connect the pacemaker!')

                            
                        
                                           

                    window = Tk()
                    window.geometry('925x320+300+150')
                    Label(window, text = ("Pacemaker User:", user.get()), font = ("Calibri", 13)).place(x=400,y=90)
                    Label(window, text =("LOWER RATE LIMIT:", VOO_LOWER_RATE), font = ("Calibri", 13)).place(x=400,y=130)
                    Label(window, text = ("UPPER RATE LIMIT:", VOO_UPPER_RATE), font = ("Calibri", 13)).place(x=400,y=170)
                    Label(window, text =("Vent AMPLITUDE:", VOO_VENTRICUALAR_AMP), font = ("Calibri", 13)).place(x=400,y=210)
                    Label(window, text =("Vent PULSE WIDTH:", VOO_VENTRICULAR_PW), font = ("Calibri", 13)).place(x=400,y=250)
                   
                    Label(window, text = "Selected Values for VOO:", font = ("Calibri", 13)).place(x=400,y=50)
                    Button(window, text = "Confirm", width="5", height = "1", command = loaded).place(x=850,y=250)
                    Button(window, text="Edit", command=window.destroy).place(x=850,y=280) #button to close the window

 

    elif SET_CURRENT_MODE=='AOO':
        f = open("IMPORT.json", "r+")
        data = json.load(f)
        for INCREMENTED in data:
            if INCREMENTED["username"] == user.get():
                if INCREMENTED["AOO"]["UPPER RL"] == "":
                    print("Nothing to load, save parameters first")
                    print("USER:", user.get())
                else:
                    AOO_LOWER_RATE = INCREMENTED["AOO"]["LOWER RL"]
                    AOO_UPPER_RATE = INCREMENTED["AOO"]["UPPER RL"]
                    AOO_ATRIAL_AMP = INCREMENTED["AOO"]["ATRIAL AMPLITUDE"]
                    AOO_ATRIAL_PW = INCREMENTED["AOO"]["ATRIAL PW"]
                    
                    def loaded():
                        '''
                        print("________________________________________________________")  
                        print("PREVIOUS VALUES FOR AOO")
                        print("Pacemaker User:", user.get())
                        print("LOWER RATE LIMIT:", AOO_LOWER_RATE)
                        print("UPPER RATE LIMIT:", AOO_UPPER_RATE)
                        print("ATRIAL AMPLITUDE:", AOO_ATRIAL_AMP)
                        print("ATRIAL PULSE WIDTH:", AOO_ATRIAL_PW) 
                        print("________________________________________________________") 
                        '''
                        try:
                            time.sleep(0.5)

                            Pace_mode = 1 #0 - VTR, 1 - ATR
                            Sensing_control = 0 #0 - OFF, 1 - ON
                            Ventricle_amplitude = 0 #In *10 volts, so 3.5V
                            Atrial_amplitude = int(float(AOO_ATRIAL_AMP)*10)
                            Atrial_pace_width = int(float(AOO_ATRIAL_PW))
                            Ventricle_pace_width = 0
                            Atrial_rf_period = 0 #in ms (requires short)
                            Ventricle_rf_period = 0
                            Lower_rate_limit = int(AOO_LOWER_RATE) #in ms
                            Upper_rate_limit = int(AOO_UPPER_RATE)
                            Atrial_sensitivity = 26 #in *10 volts
                            Ventricle_sensitivity = 0



                            start_byte = b'\x16'
                            echo_byte = b'\x22'
                            set_byte = b'\x55'

                            Pace_Mode = struct.pack("B", Pace_mode)
                            Sensing_Control = struct.pack("B", Sensing_control)
                            Atrial_Amplitude = struct.pack("B",Atrial_amplitude )
                            Ventricle_Amplitude = struct.pack("B", Ventricle_amplitude)
                            Atrial_PaceWidth = struct.pack("B", Atrial_pace_width)
                            Ventricle_PaceWidth = struct.pack("B", Ventricle_pace_width)
                            Atrial_Refractory_Period = struct.pack("H", Atrial_rf_period)
                            Ventricle_Refractory_Period = struct.pack("H", Ventricle_rf_period)
                            LRL = struct.pack("B", Lower_rate_limit)
                            URL = struct.pack("B", Upper_rate_limit)
                            Atrial_Sensitivity = struct.pack("B", Atrial_sensitivity)
                            Ventricle_Sensitivity = struct.pack("B", Ventricle_sensitivity)


                            Signal_set = start_byte + set_byte + Pace_Mode + Sensing_Control + Atrial_Amplitude + Ventricle_Amplitude + Atrial_PaceWidth + Ventricle_PaceWidth + Atrial_Refractory_Period + Ventricle_Refractory_Period + LRL + URL + Atrial_Sensitivity + Ventricle_Sensitivity
                            Signal_echo = start_byte + echo_byte + Pace_Mode + Sensing_Control + Atrial_Amplitude + Ventricle_Amplitude + Atrial_PaceWidth + Ventricle_PaceWidth + Atrial_Refractory_Period + Ventricle_Refractory_Period + LRL + URL + Atrial_Sensitivity + Ventricle_Sensitivity
                                            
                            print("Params Being Sent...")
                            ser.write(Signal_set)


                            ser.write(Signal_echo)
                            print("running")
                            data = ser.read(14)
                            print("still running")
                            v1 = data[0]
                            v2 = data[1]
                            v3 = data[2]
                            v4 = data[3]
                            v5 = data[4]
                            v6 = data[5]
                            v7 = struct.unpack("H", data[6:8])[0]
                            v8 = struct.unpack("H", data[8:10])[0]
                            v9 = data[10]
                            v10 = data[11]
                            v11 = data[12]
                            v12 = data[13]
                            
                            

                            print("From the board:")
                            print("Pace_mode = ", v1)
                            print("Sensing_control = ", v2)
                            print("Atrial_Amplitude = ", v3)
                            print("Ventricle_Amplitude = ", v4)
                            print("Atrial_PaceWidth = ", v5)
                            print("Ventricle_PaceWidth = ", v6)
                            print("Atrial_Refractory_Period = ", v7)
                            print("Ventricle_Refractory_Period = ", v8)
                            print("LRL = ", v9)
                            print("URL = ", v10)
                            print("Atrial_Sensitivity = ", v11)
                            print("Ventricle_Sensitivity = ", v12)
                        except:
                            messagebox.showerror('Error', 'Make sure to connect the pacemaker!')

                        Label(window, text = ("Pacemaker User:", user.get()), font = ("Calibri", 13)).place(x=400,y=90)
                        Label(window, text =("LOWER RATE LIMIT:", AOO_LOWER_RATE), font = ("Calibri", 13)).place(x=400,y=130)
                        Label(window, text = ("UPPER RATE LIMIT:", AOO_UPPER_RATE), font = ("Calibri", 13)).place(x=400,y=170)
                        Label(window, text =("Atrial AMPLITUDE:", AOO_ATRIAL_AMP), font = ("Calibri", 13)).place(x=400,y=210)
                        Label(window, text =("Atrial PULSE WIDTH:", AOO_ATRIAL_PW), font = ("Calibri", 13)).place(x=400,y=250)
           
              

                    window = Tk()
                    window.geometry('925x320+300+150')
                   
                    Label(window, text = "Selected Values for AOO:", font = ("Calibri", 13)).place(x=400,y=50)


                    Label(window, text = ("Pacemaker User:", user.get()), font = ("Calibri", 13)).place(x=400,y=90)
                    Label(window, text =("LOWER RATE LIMIT:", AOO_LOWER_RATE), font = ("Calibri", 13)).place(x=400,y=130)
                    Label(window, text = ("UPPER RATE LIMIT:", AOO_UPPER_RATE), font = ("Calibri", 13)).place(x=400,y=170)
                    Label(window, text =("Atrial AMPLITUDE:", AOO_ATRIAL_AMP), font = ("Calibri", 13)).place(x=400,y=210)
                    Label(window, text =("Atrial PULSE WIDTH:", AOO_ATRIAL_PW), font = ("Calibri", 13)).place(x=400,y=250)
           
                    Button(window, text = "Confirm", width="5", height = "1", command = loaded).place(x=850,y=250)
                    Button(window, text="Edit", command=window.destroy).place(x=850,y=280) #button to close the window
     
    elif SET_CURRENT_MODE=='VVI':
        f = open("IMPORT.json", "r+")
        data = json.load(f)
        for INCREMENTED in data:
            if INCREMENTED["username"] == user.get():
                if INCREMENTED["VVI"]["UPPER RL"] == "":
                    print("Nothing to load, save parameters first")
                    print("USER:", user.get())
                else:
                    VVI_LOWER_RATE = INCREMENTED["VVI"]["LOWER RL"]
                    VVI_UPPER_RATE = INCREMENTED["VVI"]["UPPER RL"]
                    VVI_VENTRICAL_AMP = INCREMENTED["VVI"]["VA"]
                    VVI_VENTRICAL_PW = INCREMENTED["VVI"]["VENTRICULAR PULSE WIDTH"]
                    VVI_VRP = INCREMENTED["VVI"]["VRP"]
                    VVI_VENTRICULAR_SENSITIVITY = INCREMENTED["VVI"]["VS"]
                    VVI_HYSTEREISIS = INCREMENTED["VVI"]["H"]
                    VVI_RATE_SMOOTHINGS = INCREMENTED["VVI"]["S"]
                    def loaded():
                        try:
                            time.sleep(0.5)

                            Pace_mode = 0 #0 - VTR, 1 - ATR
                            Sensing_control = 1 #0 - OFF, 1 - ON
                            Ventricle_amplitude = int(float(VVI_VENTRICAL_AMP)*10) #In *10 volts, so 3.5V
                            Atrial_amplitude = 0
                            Atrial_pace_width = 0
                            Ventricle_pace_width = int(float(VVI_VENTRICAL_PW))
                            Atrial_rf_period = 0 #in ms (requires short)
                            Ventricle_rf_period = int(VVI_VRP)
                            Lower_rate_limit = int(VVI_LOWER_RATE) #in ms
                            Upper_rate_limit = int(VVI_UPPER_RATE)
                            Atrial_sensitivity = 0 #in *10 volts
                            Ventricle_sensitivity = int(float(VVI_VENTRICULAR_SENSITIVITY)*10)



                            start_byte = b'\x16'
                            echo_byte = b'\x22'
                            set_byte = b'\x55'

                            Pace_Mode = struct.pack("B", Pace_mode)
                            Sensing_Control = struct.pack("B", Sensing_control)
                            Atrial_Amplitude = struct.pack("B",Atrial_amplitude )
                            Ventricle_Amplitude = struct.pack("B", Ventricle_amplitude)
                            Atrial_PaceWidth = struct.pack("B", Atrial_pace_width)
                            Ventricle_PaceWidth = struct.pack("B", Ventricle_pace_width)
                            Atrial_Refractory_Period = struct.pack("H", Atrial_rf_period)
                            Ventricle_Refractory_Period = struct.pack("H", Ventricle_rf_period)
                            LRL = struct.pack("B", Lower_rate_limit)
                            URL = struct.pack("B", Upper_rate_limit)
                            Atrial_Sensitivity = struct.pack("B", Atrial_sensitivity)
                            Ventricle_Sensitivity = struct.pack("B", Ventricle_sensitivity)


                            Signal_set = start_byte + set_byte + Pace_Mode + Sensing_Control + Atrial_Amplitude + Ventricle_Amplitude + Atrial_PaceWidth + Ventricle_PaceWidth + Atrial_Refractory_Period + Ventricle_Refractory_Period + LRL + URL + Atrial_Sensitivity + Ventricle_Sensitivity
                            Signal_echo = start_byte + echo_byte + Pace_Mode + Sensing_Control + Atrial_Amplitude + Ventricle_Amplitude + Atrial_PaceWidth + Ventricle_PaceWidth + Atrial_Refractory_Period + Ventricle_Refractory_Period + LRL + URL + Atrial_Sensitivity + Ventricle_Sensitivity
                                            
                            print("Params Being Sent...")
                            ser.write(Signal_set)


                            ser.write(Signal_echo)
                            print("running")
                            data = ser.read(14)
                            print("still running")
                            v1 = data[0]
                            v2 = data[1]
                            v3 = data[2]
                            v4 = data[3]
                            v5 = data[4]
                            v6 = data[5]
                            v7 = struct.unpack("H", data[6:8])[0]
                            v8 = struct.unpack("H", data[8:10])[0]
                            v9 = data[10]
                            v10 = data[11]
                            v11 = data[12]
                            v12 = data[13]
                            
                            

                            print("From the board:")
                            print("Pace_mode = ", v1)
                            print("Sensing_control = ", v2)
                            print("Atrial_Amplitude = ", v3)
                            print("Ventricle_Amplitude = ", v4)
                            print("Atrial_PaceWidth = ", v5)
                            print("Ventricle_PaceWidth = ", v6)
                            print("Atrial_Refractory_Period = ", v7)
                            print("Ventricle_Refractory_Period = ", v8)
                            print("LRL = ", v9)
                            print("URL = ", v10)
                            print("Atrial_Sensitivity = ", v11)
                            print("Ventricle_Sensitivity = ", v12)
                        except:
                            messagebox.showerror('Error', 'Make sure to connect the pacemaker!')


                        #print("________________________________________________________")
                        #print("PREVIOUS VALUES FOR VVI")
                        #print("Pacemaker User:", user.get())
                        #print("LOWER RATE LIMIT:", VVI_LOWER_RATE)
                        #print("UPPER RATE LIMIT:", VVI_UPPER_RATE)
                        ##print("VENTRICULAR AMPLITUDE:", VVI_VENTRICAL_AMP)
                        #print("VENTRICULAR PULSE WIDTH:", VVI_VENTRICAL_PW)
                        ##print("VENTRICULAR SENSITIVITY:", VVI_VENTRICULAR_SENSITIVITY)
                        ##print("VRP:", VVI_VRP)
                        #print("HYSTERESIS:", VVI_HYSTEREISIS)
                        #print("RATE SMOOTHING:", VVI_RATE_SMOOTHINGS) # dont know what to put for that right here 
                        #print("________________________________________________________")     




                        Label(window, text = ("Pacemaker User:", user.get()), font = ("Calibri", 13)).place(x=400,y=40)
                        Label(window, text =("LOWER_RATE", VVI_LOWER_RATE), font = ("Calibri", 13)).place(x=400,y=80)
                        Label(window, text = ("UPPER RATE LIMIT:", VVI_UPPER_RATE), font = ("Calibri", 13)).place(x=400,y=120)
                        Label(window, text =("Ventricular AMPLITUDE:", VVI_VENTRICAL_AMP), font = ("Calibri", 13)).place(x=400,y=160)
                        Label(window, text =("Ventricular PULSE WIDTH:", VVI_VENTRICAL_PW), font = ("Calibri", 13)).place(x=400,y=200)
                        Label(window, text =("VRP:", VVI_VRP), font = ("Calibri", 13)).place(x=400,y=240)
                        Label(window, text =("VENTRICULAR_SENSITIVITY:", VVI_VENTRICULAR_SENSITIVITY), font = ("Calibri", 13)).place(x=400,y=280)
                        Label(window, text =("HYSTEREISIS:", VVI_HYSTEREISIS), font = ("Calibri", 13)).place(x=400,y=320)
                        Label(window, text =("Rate Smoothings:", VVI_RATE_SMOOTHINGS), font = ("Calibri", 13)).place(x=400,y=360)
           
              

                    window = Tk()
                    window.geometry('925x520+300+150')
                    
                    Label(window, text = "Selected Values for VVI:", font = ("Calibri", 13)).place(x=400,y=60)
                    Label(window, text = ("Pacemaker User:", user.get()), font = ("Calibri", 13)).place(x=400,y=40)
                    Label(window, text =("LOWER_RATE", VVI_LOWER_RATE), font = ("Calibri", 13)).place(x=400,y=80)
                    Label(window, text = ("UPPER RATE LIMIT:", VVI_UPPER_RATE), font = ("Calibri", 13)).place(x=400,y=120)
                    Label(window, text =("Ventricular AMPLITUDE:", VVI_VENTRICAL_AMP), font = ("Calibri", 13)).place(x=400,y=160)
                    Label(window, text =("Ventricular PULSE WIDTH:", VVI_VENTRICAL_PW), font = ("Calibri", 13)).place(x=400,y=200)
                    Label(window, text =("VRP:", VVI_VRP), font = ("Calibri", 13)).place(x=400,y=240)
                    Label(window, text =("VENTRICULAR_SENSITIVITY:", VVI_VENTRICULAR_SENSITIVITY), font = ("Calibri", 13)).place(x=400,y=280)
                    Label(window, text =("HYSTEREISIS:", VVI_HYSTEREISIS), font = ("Calibri", 13)).place(x=400,y=320)
                    Label(window, text =("Rate Smoothings:", VVI_RATE_SMOOTHINGS), font = ("Calibri", 13)).place(x=400,y=360)
                    
                    Button(window, text = "Confirm", width="6", height = "1", command = loaded).place(x=850,y=250)
                    Button(window, text="Edit", command=window.destroy).place(x=850,y=280) #button to close the window
                    

    elif SET_CURRENT_MODE=='AAI':
        f = open("IMPORT.json", "r+")
        data = json.load(f)
        for INCREMENTED in data:
            if INCREMENTED["username"] == user.get():
                if INCREMENTED["AAI"]["UPPER RL"] == "":
                    print("Nothing to load, save parameters first")
                    print("USER:", user.get())
                else:
                    AAI_LOWER_RATE = INCREMENTED["AAI"]["LOWER RL"]
                    AAI_UPPER_RATE = INCREMENTED["AAI"]["UPPER RL"]
                    AAI_ATRIAL_AMP = INCREMENTED["AAI"]["ATRIAL AMPLITUDE"]
                    AAI_APW = INCREMENTED["AAI"]["ATRIAL PW"]
                    AAI_ARP = INCREMENTED["AAI"]["ARP"]
                    AAI_ATRIAL_SENSETIVITY = INCREMENTED["AAI"]["AS"]
                    AAI_PVARP = INCREMENTED["AAI"]["PVARP"]
                    AAI_HYSTERESIS = INCREMENTED["AAI"]["H"]
                    AAI_RATE_SMOOTHING = INCREMENTED["AAI"]["S"]

                    def loaded():
                        try:
                            
                            time.sleep(0.5)

                            Pace_mode = 0 #0 - VTR, 1 - ATR
                            Sensing_control = 1 #0 - OFF, 1 - ON
                            Ventricle_amplitude = 0 #In *10 volts, so 3.5V
                            Atrial_amplitude = int(float(AAI_ATRIAL_AMP)*10)
                            Atrial_pace_width = int(float(AAI_APW))
                            Ventricle_pace_width = 0
                            Atrial_rf_period = 0 #in ms (requires short)
                            Ventricle_rf_period = int(AAI_ARP)
                            Lower_rate_limit = int(AAI_LOWER_RATE) #in ms
                            Upper_rate_limit = int(AAI_UPPER_RATE)
                            Atrial_sensitivity = 0 #in *10 volts
                            Ventricle_sensitivity = int(float(AAI_ATRIAL_SENSETIVITY)*10)



                            start_byte = b'\x16'
                            echo_byte = b'\x22'
                            set_byte = b'\x55'

                            Pace_Mode = struct.pack("B", Pace_mode)
                            Sensing_Control = struct.pack("B", Sensing_control)
                            Atrial_Amplitude = struct.pack("B",Atrial_amplitude )
                            Ventricle_Amplitude = struct.pack("B", Ventricle_amplitude)
                            Atrial_PaceWidth = struct.pack("B", Atrial_pace_width)
                            Ventricle_PaceWidth = struct.pack("B", Ventricle_pace_width)
                            Atrial_Refractory_Period = struct.pack("H", Atrial_rf_period)
                            Ventricle_Refractory_Period = struct.pack("H", Ventricle_rf_period)
                            LRL = struct.pack("B", Lower_rate_limit)
                            URL = struct.pack("B", Upper_rate_limit)
                            Atrial_Sensitivity = struct.pack("B", Atrial_sensitivity)
                            Ventricle_Sensitivity = struct.pack("B", Ventricle_sensitivity)


                            Signal_set = start_byte + set_byte + Pace_Mode + Sensing_Control + Atrial_Amplitude + Ventricle_Amplitude + Atrial_PaceWidth + Ventricle_PaceWidth + Atrial_Refractory_Period + Ventricle_Refractory_Period + LRL + URL + Atrial_Sensitivity + Ventricle_Sensitivity
                            Signal_echo = start_byte + echo_byte + Pace_Mode + Sensing_Control + Atrial_Amplitude + Ventricle_Amplitude + Atrial_PaceWidth + Ventricle_PaceWidth + Atrial_Refractory_Period + Ventricle_Refractory_Period + LRL + URL + Atrial_Sensitivity + Ventricle_Sensitivity
                                            
                            print("Params Being Sent...")
                            ser.write(Signal_set)


                            ser.write(Signal_echo)
                            print("running")
                            data = ser.read(14)
                            print("still running")
                            v1 = data[0]
                            v2 = data[1]
                            v3 = data[2]
                            v4 = data[3]
                            v5 = data[4]
                            v6 = data[5]
                            v7 = struct.unpack("H", data[6:8])[0]
                            v8 = struct.unpack("H", data[8:10])[0]
                            v9 = data[10]
                            v10 = data[11]
                            v11 = data[12]
                            v12 = data[13]
                            
                            

                            print("From the board:")
                            print("Pace_mode = ", v1)
                            print("Sensing_control = ", v2)
                            print("Atrial_Amplitude = ", v3)
                            print("Ventricle_Amplitude = ", v4)
                            print("Atrial_PaceWidth = ", v5)
                            print("Ventricle_PaceWidth = ", v6)
                            print("Atrial_Refractory_Period = ", v7)
                            print("Ventricle_Refractory_Period = ", v8)
                            print("LRL = ", v9)
                            print("URL = ", v10)
                            print("Atrial_Sensitivity = ", v11)
                            print("Ventricle_Sensitivity = ", v12)
                        except:
                            messagebox.showerror('Error', 'Make sure to connect the pacemaker!')



                        '''
                        print("________________________________________________________")
                        print("PREVIOUS VALUES FOR AAI")
                        print("Pacemaker User:", user.get())
                        print("LOWER RATE LIMIT:", AAI_LOWER_RATE)
                        print("UPPER RATE LIMIT:", AAI_UPPER_RATE)
                        print("ATRIAL AMPLITUDE:", AAI_ATRIAL_AMP)
                        print("ATRIAL PULSE WIDTH:", AAI_APW)
                        print("ATRIAL SENSITIVITY:", AAI_ATRIAL_SENSETIVITY)
                        print("ARP:", AAI_ARP)
                        print("PVARP:", AAI_PVARP)
                        print("HYSTERESIS:", AAI_HYSTERESIS)
                        print("RATE SMOOTHING:", AAI_RATE_SMOOTHING)
                        print("________________________________________________________")
                        
                        Label(window, text = ("Pacemaker User:", user.get()), font = ("Calibri", 13)).place(x=400,y=40)
                        Label(window, text =("LOWER_RATE",  AAI_LOWER_RATE), font = ("Calibri", 13)).place(x=400,y=80)
                        Label(window, text = ("UPPER RATE LIMIT:", AAI_UPPER_RATE), font = ("Calibri", 13)).place(x=400,y=120)
                        Label(window, text =("Atrial AMPLITUDE:", AAI_ATRIAL_AMP), font = ("Calibri", 13)).place(x=400,y=160)
                        Label(window, text =("AAI_APW:", AAI_APW), font = ("Calibri", 13)).place(x=400,y=200)
                        Label(window, text =("AAI_ARP:", AAI_ARP), font = ("Calibri", 13)).place(x=400,y=240)
                        Label(window, text =("Atrial SENSITIVITY:", AAI_ATRIAL_SENSETIVITY), font = ("Calibri", 13)).place(x=400,y=280)
                        Label(window, text =("PVARP:", AAI_PVARP), font = ("Calibri", 13)).place(x=400,y=300)
                        Label(window, text =("HYSTEREISIS:", AAI_HYSTERESIS), font = ("Calibri", 13)).place(x=400,y=320)
                        Label(window, text =("Rate Smoothings:", AAI_RATE_SMOOTHING), font = ("Calibri", 13)).place(x=400,y=360)
                        '''


                    window = Tk()
                    window.geometry('925x520+300+150')

                    Label(window, text = ("Pacemaker User:", user.get()), font = ("Calibri", 13)).place(x=400,y=40)
                    Label(window, text = "Selected Values for AAI:", font = ("Calibri", 13)).place(x=400,y=60)
                    Label(window, text =("LOWER_RATE",  AAI_LOWER_RATE), font = ("Calibri", 13)).place(x=400,y=80)
                    Label(window, text = ("UPPER RATE LIMIT:", AAI_UPPER_RATE), font = ("Calibri", 13)).place(x=400,y=120)
                    Label(window, text =("Atrial AMPLITUDE:", AAI_ATRIAL_AMP), font = ("Calibri", 13)).place(x=400,y=160)
                    Label(window, text =("AAI_APW:", AAI_APW), font = ("Calibri", 13)).place(x=400,y=200)
                    Label(window, text =("AAI_ARP:", AAI_ARP), font = ("Calibri", 13)).place(x=400,y=240)
                    Label(window, text =("Atrial SENSITIVITY:", AAI_ATRIAL_SENSETIVITY), font = ("Calibri", 13)).place(x=400,y=280)
                    Label(window, text =("PVARP:", AAI_PVARP), font = ("Calibri", 13)).place(x=400,y=300)
                    Label(window, text =("HYSTEREISIS:", AAI_HYSTERESIS), font = ("Calibri", 13)).place(x=400,y=320)
                    Label(window, text =("Rate Smoothings:", AAI_RATE_SMOOTHING), font = ("Calibri", 13)).place(x=400,y=360)
                    
                    Button(window, text = "Confirm", width="6", height = "1", command = loaded).place(x=850,y=250)
                    Button(window, text="Edit", command=window.destroy).place(x=850,y=280) #button to close the window
                    

wind.mainloop()


# In[ ]:





# In[ ]:

#!/usr/bin/env python
# coding: utf-8

# In[ ]:


#10/23/2022 
#BY AHMED ABDELHALIM 400313465 abdela55 / SARA ARMANZI 400324304 armanazs
import json
from tkinter import *
from tkinter import messagebox
import ast
from tkinter import ttk
from tokenize import Special
wind = Tk()
wind.title("Login")
wind.geometry('925x500+300+150')
wind.configure(bg='#fff')
wind.resizable(False, False)

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
           
        def DISPLAY():
            global LOWER_RATE_LIMIT
            global UPPER_RATE_LIMIT
            global B_AMPLITUDE
            global PULSE_WIDTH
            LOWER_RATE_LIMIT = list.get()
            B_AMPLITUDE = list1.get()
            PULSE_WIDTH = list2.get()
            SET_VALS()
            Label(master, text = "Your values have been saved", font = ("Calibri", 13)).place(x=350,y=400)

        Button(master, text = "Save", width="3", height = "1", command = DISPLAY).pack()
        Button(master, text = "load", width="3", height = "1", command = ACCESS_LOAD).pack()
        Button(master, text="Back", command=master.destroy).pack() #button to close the window
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
        
        
        
        def DISPLAY():
            global LOWER_RATE_LIMIT
            global UPPER_RATE_LIMIT
            global B_AMPLITUDE
            global PULSE_WIDTH
            LOWER_RATE_LIMIT = list.get()
            B_AMPLITUDE = list1.get()
            PULSE_WIDTH = list2.get()
            SET_VALS()
            Label(master, text = "Your values have been saved", font = ("Calibri", 13)).place(x=350,y=400)
            # print("_____________________________________")
            # print("The values for VOO :")
            # print("LOWER RATE LIMIT : ",LOWER_RATE_LIMIT)
            # print("UPPER RATE LIMIT : ", UPPER_RATE_LIMIT.get()) 
            # print("VENT AMPLITUDE : ",B_AMPLITUDE)
            # print("VENT PULSE WIDTH : ",PULSE_WIDTH)
            # print("_____________________________________")
        Button(master, text = "Save", width="3", height = "1", command = DISPLAY).pack()
        Button(master, text = "load", width="3", height = "1", command = ACCESS_LOAD).pack()
        Button(master, text="Back", command=master.destroy).pack() #button to close the window
        Label(master, text = "Pacemaker User:  %s" % (username),font = ("Calibri", 13)).pack(side = LEFT )

        Label(master, text = "").pack()   
        



    ###############################################################
############################################################## 
# 
# 
# 
#    
    def AAI(): #function when button is clicked   
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

        
        
        
        
        
        Label(master, text = "Atrial Pulse Width (ms)").pack()
        CHOICES2 = [
            "0.05","0.1","0.2","0.3","0.4","0.5","0.6","0.7","0.8","0.9","1.0","1.1","1.2","1.3","1.4","1.5","1.6","1.7","1.8","1.9",
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
            "0.25","0.5","0.75","1","1.5","2","2.5","3","3.5","4","4.5","5","5.5","6","6.5","7","7.5","8","8.5","9","9.5","10"]
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
            Label(master, text = "Your values have been saved", font = ("Calibri", 13)).place(x=350,y=820)
            # print("_____________________________________")
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
        Button(master, text = "load", width="3", height = "1", command = ACCESS_LOAD).pack()
        Button(master, text="Back", command=master.destroy).pack() #button to close the window
        Label(master, text = "Pacemaker User:  %s" % (username),font = ("Calibri", 13)).pack(side = LEFT )

        Label(master, text = "").pack()
       
    ###############################################################
############################################################## 
# 
# 
# 
#    
        
    def VVI(): #function when button is clicked   
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
            "0.25","0.5","0.75","1","1.5","2","2.5","3","3.5","4","4.5","5","5.5","6","6.5","7","7.5","8","8.5","9","9.5","10"]
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
            Label(master, text = "Your values have been saved", font = ("Calibri", 13)).place(x=350,y=670)
            # print("_____________________________________")
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
        Button(master, text = "load", width="3", height = "1", command = ACCESS_LOAD).pack()
        Button(master, text="Back", command=master.destroy).pack() #button to close the window
        Label(master, text = "Pacemaker User:  %s" % (username),font = ("Calibri", 13)).pack(side = LEFT )

        Label(master, text = "").pack()
  ###############################################################

           #                  CONNECT SCREEN + MODES                   

###############################################################      
    def connect():
        screen.destroy()
        messagebox.showinfo('Success','Device Connected!')
     
        
        window = Tk()
        window.geometry('925x320+300+150')
        button2 = Button(window,width=20, pady=6,  text= "1.    AOO",bg='white', fg='black', border=1,command=AOO).place(x=420,y=40) #input button
     
        Label(window, text = "Please select your mode:", font = ("Calibri", 13)).place(x=420,y=20)

       
#############################################BUTTONS FOR MODES

        button3 = Button(window,width=20, pady=6,  text= "2.    VVI",bg='white', fg='black', border=1,command=VVI).place(x=420,y=100) #input button
   
        button4 = Button(window,width=20, pady=6,  text= "3.    VOO",bg='white', fg='black', border=1,command=VOO).place(x=420,y=160) #input button
    
        button5 = Button(window,width=20, pady=6, text= "4.     AAI",bg='white', fg='black', border=1,command=AAI).place(x=420,y=220) #input button
      

        Button(window, width=20, pady=2, text="Logout",bg='black', fg='white', border=1, command=window.destroy).place(x=420, y=280) #button to close the window
        Label(window, text = "Pacemaker User:  %s" % (username),font = ("Calibri", 13)).pack(side = LEFT )
        Label(window, text = "CONNECTED TO PACEMAKER",fg = 'green' ,font = 'Helvetica 9 bold').pack(side = RIGHT)

        
        window.mainloop()
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
                        print("________________________________________________________") 
                        print("PREVIOUS VALUES FOR VOO")
                        print("Pacemaker User:", user.get())
                        print("LOWER RATE LIMIT:", VOO_LOWER_RATE)
                        print("UPPER RATE LIMIT:", VOO_UPPER_RATE)
                        print("Vent AMPLITUDE:", VOO_VENTRICUALAR_AMP)
                        print("Vent PULSE WIDTH:", VOO_VENTRICULAR_PW) 
                        print("________________________________________________________") 
                                           

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
                        print("________________________________________________________")  
                        print("PREVIOUS VALUES FOR AOO")
                        print("Pacemaker User:", user.get())
                        print("LOWER RATE LIMIT:", AOO_LOWER_RATE)
                        print("UPPER RATE LIMIT:", AOO_UPPER_RATE)
                        print("ATRIAL AMPLITUDE:", AOO_ATRIAL_AMP)
                        print("ATRIAL PULSE WIDTH:", AOO_ATRIAL_PW) 
                        print("________________________________________________________") 
                        
     
                        
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
                        
                        print("________________________________________________________")
                        print("PREVIOUS VALUES FOR VVI")
                        print("Pacemaker User:", user.get())
                        print("LOWER RATE LIMIT:", VVI_LOWER_RATE)
                        print("UPPER RATE LIMIT:", VVI_UPPER_RATE)
                        print("VENTRICULAR AMPLITUDE:", VVI_VENTRICAL_AMP)
                        print("VENTRICULAR PULSE WIDTH:", VVI_VENTRICAL_PW)
                        print("VENTRICULAR SENSITIVITY:", VVI_VENTRICULAR_SENSITIVITY)
                        print("VRP:", VVI_VRP)
                        print("HYSTERESIS:", VVI_HYSTEREISIS)
                        print("RATE SMOOTHING:", VVI_RATE_SMOOTHINGS)
                        print("________________________________________________________")     
                        
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




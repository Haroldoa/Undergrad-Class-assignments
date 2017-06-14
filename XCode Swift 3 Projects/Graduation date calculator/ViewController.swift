//
//  ViewController.swift
//  Graduation date calculator

//  Created by Haroldo Altamirano on 6/2/17.
//  Copyright © 2017 Haroldo Altamirano. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    @IBOutlet weak var fallGradMonth: UITextField!
    @IBOutlet weak var springGradMonth: UITextField!
    @IBOutlet weak var semestersUntilGraduation: UITextField!
    @IBOutlet weak var graduateMonthYear: UITextField!

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }
    @IBAction func calculateGradDate(_ sender: Any) {
        // Calculate and output grad month and year from user inputted data
        
        // Declare local variables
        let fGradString = fallGradMonth.text
        let sGradString = springGradMonth.text
        let semestersString = semestersUntilGraduation.text
        
        let semestersLeft = Int(semestersString!)   // get int value from input
        var fGradMonth: Int, sGradMonth: Int    //for converting strings to ints
        var yourGradDate = ""   // for outputting calculated month and year
        var nextSemesterIsFall: Bool    // for calculating grad month, false is spring
        
        let currentDate = Date()
        let calendar = Calendar.current
        let currentMonth = calendar.component(.month, from: currentDate)  // user month
        let currentYear = calendar.component(.year, from: currentDate)  // user year, for calculating user's grad month and year
        var calcMonth = currentMonth, calcYear = currentYear   // for temporarilly storing grad Date data, initialized for calculation loops
        
        // Validate input for 3 text fields (fall month, spring month, semester number)
        if (fGradString == "")  { // empty field
        return
        } else if (sGradString == "") { // empty field
            return
        } else if (semestersString == "") { // empty field
            return
        }
        
        // Done validating empty fields
        // Declare functions:
        
        func month_ConvertStringtoInt (month : String) -> Int{
            // Take user input string month and return a standard int value
            
            /* Remove punctuation
            month = month.stringByReplacingOccurrencesOfString(".", withString: "", options: .allZeros, range: nil) */
            
            // standardize january input
            if (month == "jan") || (month == "Jan")
                || (month == "january") || (month == "January")
                || (month == "01") || (month == "1")  {
                return 1
            }
            // standardize february input
            if (month == "feb") || (month == "Feb")
                || (month == "february") || (month == "February")
                || (month == "02") || (month == "2")  {
                return 2
            }
            // standardize march input
            if (month == "mar") || (month == "Mar")
                || (month == "march") || (month == "March")
                || (month == "03") || (month == "3")  {
                return 3
            }
            // standardize april input
            if (month == "apr") || (month == "Apr")
                || (month == "april") || (month == "April")
                || (month == "04") || (month == "4")  {
                return 4
            }
            // standardize may input
            if (month == "may") || (month == "May")
                || (month == "05") || (month == "5")  {
                return 5
            }
            // standardize june input
            if (month == "jun") || (month == "Jun")
                || (month == "june") || (month == "June")
                || (month == "06") || (month == "6")  {
                return 6
            }
            // standardize july input
            if (month == "jul") || (month == "Jul")
                || (month == "july") || (month == "July")
                || (month == "07") || (month == "7")  {
                return 7
            }
            // standardize august input
            if (month == "aug") || (month == "Aug")
                || (month == "august") || (month == "August")
                || (month == "08") || (month == "8")  {
                return 8
            }
            // standardize september input
            if (month == "sep") || (month == "Sep")
                || (month == "september") || (month == "September")
                || (month == "09") || (month == "9")  {
                return 9
            }
            // standardize october input
            if (month == "oct") || (month == "Oct")
                || (month == "october") || (month == "October")
                || (month == "10") {
                return 10
            }
            // standardize november input
            if (month == "nov") || (month == "Nov")
                || (month == "november") || (month == "November")
                || (month == "11") {
                return 11
            }
            // standardize october input
            if (month == "dec") || (month == "Dec")
                || (month == "december") || (month == "December")
                || (month == "12") {
                return 12
            }
            else {
                return -1 // error
            }
        }
        
        func convertNumberToMonth (num: Int) -> String {
            // Convert a number to a month string
            
            if (num <= 0 || num >= 13)  {
                return ""   //empty, out of bounds
            }
            if num == 1 {
                return "January"
            }
            if num == 2 {
                return "February"
            }
            if num == 3 {
                return "March"
            }
            if num == 4 {
                return "April"
            }
            if num == 5 {
                return "May"
            }
            if num == 6 {
                return "June"
            }
            if num == 7 {
                return "July"
            }
            if num == 8 {
                return "August"
            }
            if num == 9 {
                return "September"
            }
            if num == 10 {
                return "October"
            }
            if num == 11 {
                return "November"
            }
            if num == 12 {
                return "December"
            }
            else    {
            return ""
            }
        }
        
        // Convert month input to standard int
        fGradMonth = month_ConvertStringtoInt(month: fGradString!)
        sGradMonth = month_ConvertStringtoInt(month: sGradString!)
        
        // Calculate grad month and year
        // First, what semester is next?
        if (currentMonth <= 6)   {
            nextSemesterIsFall = true
        }
        else    {
            nextSemesterIsFall = false
        }
        
        
        if (semestersLeft == 0){
            // user is in Spring semester, will graduate
            if (currentMonth <= 6)  {
                calcMonth = sGradMonth
            } else if (currentMonth <= 12)  {
            // user is in Fall, will graduate (no semesters left)
                calcMonth = fGradMonth
            }
        }
        else    {
            for _ in stride(from: 0, to: semestersLeft!, by: 1)    {   // cycle once for each semester
           
            if (nextSemesterIsFall) {
            calcMonth = fGradMonth
            nextSemesterIsFall = false  // switch for next iteration
            } else  {// next is spring and new year
                calcMonth = sGradMonth
                calcYear += 1
                nextSemesterIsFall = true   // switch for next iteration, notice switching from spring status, so fall semester is next
            }
        }
        }
        
        // Calculation done, prepare output string
        yourGradDate = convertNumberToMonth(num: calcMonth) + " " + String(calcYear)
                                // EX: January 2017
        graduateMonthYear.text = yourGradDate
     
        
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}


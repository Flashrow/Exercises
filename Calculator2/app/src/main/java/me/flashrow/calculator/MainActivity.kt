package me.flashrow.calculator

import android.annotation.SuppressLint
import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import android.widget.Button
import android.widget.TextView
import kotlinx.android.synthetic.main.activity_main.*
import org.w3c.dom.Text

class MainActivity : AppCompatActivity() {
    private var valueStr: String = ""
    private var firstValue: Float = 0F
    private var secondValue: Float = 0F
    private var isFilled: Boolean = false
    private var dot: Boolean = false
    private var equalsValue: Int = 0
    private var operationNow: String = ""
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        val txtView: TextView = findViewById(R.id.ValueTxt)
        txtView.text = "0"

        setListeners(txtView)

    }

    private fun setListeners(txtView: TextView){
        button_add.setOnClickListener(){
            if(!isFilled){
                firstValue = valueStr.toFloat()
                valueStr=""
                operationNow = "add"
                dot=false
            }
        }

        button_substract.setOnClickListener(){
            firstValue = valueStr.toFloat()
            valueStr=""
            operationNow = "sub"
            dot=false
        }

        button_equals.setOnClickListener(){
            dot=false
            when{
                operationNow == "add" ->{
                    secondValue = valueStr.toFloat() + firstValue
                    txtView.text = secondValue.toString()
                }
                operationNow == "sub" ->{
                    secondValue = valueStr.toFloat() - firstValue
                    txtView.text = secondValue.toString()
                }
            }
            firstValue = 0F
            valueStr = ""
            operationNow=""
        }
        button_comma.setOnClickListener(){
            if(!dot){
            valueStr+="."
            txtView.text = valueStr
            dot=true
            }
        }
        button_reset.setOnClickListener(){
            txtView.text = ""
            valueStr = ""
        }
        button0.setOnClickListener(){
            numberClick(0, txtView)
        }
        button1.setOnClickListener(){
            numberClick(1, txtView)
        }
        button2.setOnClickListener(){
            numberClick(2, txtView)
        }
        button3.setOnClickListener(){
            numberClick(3, txtView)
        }
        button4.setOnClickListener(){
            numberClick(4, txtView)
        }
        button5.setOnClickListener(){
            numberClick(5, txtView)
        }
        button6.setOnClickListener(){
            numberClick(6, txtView)
        }
        button7.setOnClickListener(){
            numberClick(7, txtView)
        }
        button8.setOnClickListener(){
            numberClick(8, txtView)
        }
        button9.setOnClickListener(){
            numberClick(9, txtView)
        }
    }

    @SuppressLint("SetTextI18n")
    private fun numberClick(n: Int?, txtView: TextView) {
        when(n){
            0 -> {
                valueStr += "0"
                txtView.text = valueStr
            }
            1 -> {
                valueStr += "1"
                txtView.text = valueStr
            }
            2 -> {
                valueStr += "2"
                txtView.text = valueStr
            }
            3 -> {
                valueStr += "3"
                txtView.text = valueStr
            }
            4 -> {
                valueStr += "4"
                txtView.text = valueStr
            }
            5 -> {
                valueStr += "5"
                txtView.text = valueStr
            }
            6 -> {
                valueStr += "6"
                txtView.text = valueStr
            }
            7 -> {
                valueStr += "7"
                txtView.text = valueStr
            }
            8 -> {
                valueStr += "8"
                txtView.text = valueStr
            }
            9 -> {
                valueStr+="9"
                txtView.text = valueStr
            }

        }
    }
}

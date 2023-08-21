# 嗚呼在實際動手做之前先來看看這個吧！
## 模型程式區
>溫控模型電風扇使用Arduino UNO R3為開發板，在啟用開發板時如果發現此板沒有序列埠功能，請加裝開發板驅動程式庫，本案件以CH340晶片為例：  
做法連結：https://sparks.gogo.co.nz/ch340.html  
>![image](https://img.onl/aPc1VL)
>  
>電路連接圖
>![image](https://img.onl/tOTXcN)
>
>貼上程式碼並上傳至Arduino UNO R3開發板，連接上圖電路，馬達即可根據溫度調整轉速。

## 實體電風扇程式區
>* 「開發板燒錄」為燒錄程式至ATtiny85的程式碼，詳細步驟請見：  
>https://jimirobot.tw/arduino-tutorial-attiny-attiny85-usb/#2_%E5%AE%89%E8%A3%9DDigispark%E7%A1%AC%E9%AB%94%E6%93%B4%E5%85%85%E5%BA%AB  
>* ATtiny開發板優點為體積小，但上傳程式需先燒錄，步驟較為麻煩，實則可以用Arduino UNO R3開發板代替之。
>  
>* 「溫溼度測試」為測試DHT11溫度感測器功能之程式碼，詳細步驟請見：  
>https://projecthub.arduino.cc/arcaegecengiz/using-dht11-12f621
>  
>* DHT11溫度感測器可測量周遭溫度及濕度數據。  
>temperature_digital_high為根據溫度控制實體交流電電風扇切換轉速之程式碼，
以高電平觸發的繼電器來切換不同段位的電風扇轉速。
>![image](https://img.onl/EJtP4d)
>ATtiny85開發板與三個1路繼電器串接簡圖

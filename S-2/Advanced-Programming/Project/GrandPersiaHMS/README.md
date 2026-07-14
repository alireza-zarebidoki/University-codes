# 🏨 Hotel Grand Persia Management System

<div dir="rtl">

سیستم مدیریت هتل کنسولی، نوشته‌شده به‌صورت کاملاً OOP در Java — بدون هیچ فریمورک یا کتابخانه‌ی خارجی.

<div dir="ltr">

![Java](https://img.shields.io/badge/Java-11%2B-orange)
![Build](https://img.shields.io/badge/build-javac-blue)
![Tests](https://img.shields.io/badge/self--test-93%2F93%20passed-brightgreen)
![License](https://img.shields.io/badge/license-Academic-lightgrey)

</div>

📂 این پروژه بخشی از یک مخزن بزرگ‌تر (`University-codes`) است؛ مسیر مستقیم پروژه:

<div dir="ltr">

[`S-2/Advanced-Programming/Project/GrandPersiaHMS`](https://github.com/alireza-zarebidoki/University-codes/tree/main/S-2/Advanced-Programming/Project/GrandPersiaHMS)

</div>

---


## درباره‌ی پروژه

این پروژه شبیه‌سازی کامل یک سیستم مدیریت هتل (هتل گرند پرشیا) است که برای درس برنامه‌سازی پیشرفته (دانشکده علوم ریاضی، دانشگاه فردوسی مشهد) پیاده‌سازی شده. سیستم چهار نقش کاربری (مدیر ارشد، مدیر هتل، منشی، مهمان) با سطوح دسترسی متفاوت دارد و تمام چرخه‌ی عملیاتی یک هتل — از رزرو و پرداخت تا عضویت، خدمات جانبی، گزارش‌گیری و لاگ امنیتی — را پوشش می‌دهد.

## ✨ ویژگی‌ها

- 🏗️ معماری لایه‌ای کامل (UI / Service / Model / Repository / Security)
- 🔑 چهار نقش کاربری با کنترل دسترسی مجزا (SuperAdmin, HotelManager, Receptionist, Guest)
- 🛏️ مدیریت کامل اتاق‌ها با ۴ نوع مختلف و فرمول قیمت‌گذاری فصلی
- 📅 چرخه‌ی کامل رزرو (Search → Reservation → Check-In → Check-Out) با الگوی Observer برای لیست انتظار
- 💳 سیستم مالی کامل: فاکتور دقیق، پرداخت قسطی، جلوگیری از خروج با بدهی معوق
- ⭐ ارتقای خودکار سطح عضویت (BRONZE → SILVER → GOLD → PLATINUM)
- 🧹 ۵ نوع خدمات جانبی (مینی‌بار، نظافت، پارکینگ، تعمیرات، سرویس اتاق)
- 📊 ۶ گزارش مدیریتی کامل
- 📝 لاگ‌گیری امنیتی استاندارد برای تمام رویدادهای حساس
- 💾 ذخیره‌سازی و بازیابی کامل داده روی فایل (بدون نیاز به دیتابیس)
- 📤 خروجی کمکی CSV (قابل‌باز‌کردن در اکسل/گوگل‌شیت) کنار فایل ذخیره‌سازی اصلی
- ✅ مجموعه تست خودکار با ۹۳ بررسی مستقل (بدون هیچ کتابخانه‌ی تست خارجی)

## 🖥️ پیش‌نمایش

<div dir="ltr">

```
╔════════════════════════════════════════════════════════╗
║ HOTEL GRAND PERSIA - Management System                  ║
╠════════════════════════════════════════════════════════╣
║ Logged in as: RECEPTIONIST | User: ali.m                 ║
╠════════════════════════════════════════════════════════╣
║ 1. Search Available Rooms                                ║
║ 2. New Reservation                                       ║
║ 3. Check-In                                               ║
║ 4. Check-Out                                              ║
║ 5. Guest Services                                         ║
║ 6. Guest History (Report R-06)                            ║
║ 0. Logout                                                 ║
╚════════════════════════════════════════════════════════╝
Select option: _
```
</div>

## 🚀 شروع سریع

### پیش‌نیاز

- JDK نسخه‌ی ۱۱ یا بالاتر

### اجرا از سورس

**گزینه‌ی ۱ — دانلود مستقیم فقط همین پوشه (ساده‌ترین راه):**

به [این لینک](https://download-directory.github.io/?url=https://github.com/alireza-zarebidoki/University-codes/tree/main/S-2/Advanced-Programming/Project/GrandPersiaHMS) بروید تا یک فایل ZIP فقط از پوشه‌ی همین پروژه دانلود شود، سپس آن را از حالت فشرده خارج کنید.

**گزینه‌ی ۲ — کلون کل مخزن:**

<div dir="ltr">

```bash
git clone https://github.com/alireza-zarebidoki/University-codes.git
cd University-codes/S-2/Advanced-Programming/Project/GrandPersiaHMS
```
</div>

**کامپایل و اجرا (مشترک بین هر دو گزینه):**

<div dir="ltr">

```bash
javac -d out $(find src -name "*.java")
java -cp out com.grandpersia.Main
```

</div>

در اولین اجرا، حساب مدیر ارشد به‌صورت خودکار ساخته می‌شود:

<div dir="ltr">

```
username: admin
password: admin123
```
</div>

### ساخت و اجرای فایل JAR

<div dir="ltr">

```bash
echo "Main-Class: com.grandpersia.Main" > manifest.txt
jar cfm hotel-management.jar manifest.txt -C out .
java -jar hotel-management.jar
```
</div>

### اجرای تست خودکار

```bash
java -cp out com.grandpersia.SelfTest
```

۹۳ بررسی مستقل روی تمام ماژول‌های سیستم اجرا می‌شود و در چند ثانیه نتیجه‌ی کامل چاپ می‌شود:

<div dir="ltr">

```
==================================================
 TEST SUMMARY: 93 passed, 0 failed (out of 93 checks)
==================================================
 ALL CHECKS PASSED.
```

</div>

### بازرسی داده‌ی ذخیره‌شده

برای دیدن محتوای فایل `hotel_data.ser` به‌صورت خوانا (بدون نیاز به اجرای کامل برنامه):

<div dir="ltr">

```bash
java -cp out com.grandpersia.DataInspector
```
</div>

همچنین بعد از هر بار ذخیره‌سازی، یک نسخه‌ی کمکی و قابل‌باز‌کردن در اکسل از همان داده‌ها در پوشه‌ی `csv_export/` هم نوشته می‌شود.

### مستندات JavaDoc

مستندات فنی کامل کلاس‌ها در پوشه‌ی `doc/` قرار دارد. برای ساخت مجدد آن از ریشه‌ی پروژه:

<div dir="ltr">

```bash
javadoc -d doc -encoding UTF-8 -charset UTF-8 -docencoding UTF-8 -private \
  -windowtitle "Hotel Grand Persia Management System" \
  $(find src -name "*.java")
```
</div>

برای مشاهده، فایل `doc/index.html` را در مرورگر باز کنید.

## 📁 ساختار پروژه

<div dir="ltr">

```
src/com/grandpersia/
├── Main.java                  نقطه‌ی ورود برنامه
├── SelfTest.java              مجموعه تست خودکار
├── DataInspector.java         ابزار مستقل بازرسی فایل داده
├── model/                     کلاس‌های داده (کاربران، اتاق‌ها، رزرو، مالی، Enum ها)
├── interfaces/                Billable, Searchable<T>, Notifiable, Exportable
├── exception/                 ۷ Exception سفارشی
├── service/                   منطق تجاری (رزرو، عضویت، مالی، اتاق، گزارش)
├── security/                  احراز هویت، کنترل دسترسی، لاگ
├── repository/                نگه‌داری داده در حافظه + ذخیره‌سازی فایل
├── ui/                        رابط کاربری کنسولی و منوهای هر نقش
└── util/                      ابزارهای کمکی
```

</div>

پوشه‌ی `doc/` (کنار `src/`) هم مستندات JavaDoc تولیدشده را نگه می‌دارد.

## 📚 مستندات

| فایل | محتوا |
|---|---|
| [`DOCUMENTATION.md`](./DOCUMENTATION.md) | توضیح کامل معماری، تمام کلاس‌ها و فیلدها، الگوهای طراحی |
| [`DOCUMENTATION.pdf`](./DOCUMENTATION.pdf) / [`DOCUMENTATION.tex`](./DOCUMENTATION.tex) | نسخه‌ی رسمی و صفحه‌بندی‌شده‌ی همان مستندات (LaTeX) |
| [`TESTING.md`](./TESTING.md) | راهنمای کامل تست خودکار و دستی |
| [`doc/index.html`](./doc/index.html) | مستندات JavaDoc  |

## 🛠️ فناوری‌ها

- **زبان:** Java (بدون هیچ فریمورک یا کتابخانه‌ی خارجی)
- **رابط کاربری:** کنسول (`Scanner` / `System.out`)
- **ذخیره‌سازی:** `java.io.Serializable` (فایل باینری، بدون دیتابیس)
- **تست:** کلاس تست خودکار سفارشی (بدون JUnit)

## 📄 یادداشت

این پروژه به‌عنوان پروژه‌ی پایان‌ترم درس برنامه‌سازی پیشرفته (دانشکده علوم ریاضی، دانشگاه فردوسی مشهد) توسعه داده شده است.


## 🙏 تشکر

از طاها و مبین عزیز، دستیاران آموزشی درس، صمیمانه تشکر می‌کنم؛ بابت وقتی که گذاشتن و با صبر و حوصله به سوالاتم پاسخ دادن.


---

<div align="center">

### 👨‍💻 علیرضا زارع بیدکی

[![GitHub](https://img.shields.io/badge/GitHub-alireza--zarebidoki-181717?style=flat&logo=github)](https://github.com/alireza-zarebidoki)
[![Email](https://img.shields.io/badge/Email-alireza%40zarebidoki.com-D14836?style=flat&logo=gmail&logoColor=white)](mailto:alireza@zarebidoki.com)

🎓 دانشکده علوم ریاضی، دانشگاه فردوسی مشهد
📘 پروژه‌ی درس برنامه‌سازی پیشرفته

</div>

---

<div align="center">

ساخته شده بدون اینترنت در ایران

</div>
</div>

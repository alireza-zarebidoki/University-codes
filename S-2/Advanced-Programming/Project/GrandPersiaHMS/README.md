# 🏨 Hotel Grand Persia Management System

سیستم مدیریت هتل کنسولی، نوشته‌شده به‌صورت کاملاً OOP در Java — بدون هیچ فریمورک یا کتابخانه‌ی خارجی.

![Java](https://img.shields.io/badge/Java-11%2B-orange)
![Build](https://img.shields.io/badge/build-javac-blue)
![Tests](https://img.shields.io/badge/self--test-79%2F79%20passed-brightgreen)
![License](https://img.shields.io/badge/license-Academic-lightgrey)

---

## درباره‌ی پروژه

این پروژه شبیه‌سازی کامل یک سیستم مدیریت هتل («هتل گرند پرشیا») است که برای درس برنامه‌سازی پیشرفته (دانشکده علوم ریاضی، دانشگاه فردوسی مشهد) پیاده‌سازی شده. سیستم چهار نقش کاربری (مدیر ارشد، مدیر هتل، منشی، مهمان) با سطوح دسترسی متفاوت دارد و تمام چرخه‌ی عملیاتی یک هتل — از رزرو و پرداخت تا عضویت، خدمات جانبی، گزارش‌گیری و لاگ امنیتی — را پوشش می‌دهد.

## ✨ ویژگی‌ها

- 🏗️ معماری لایه‌ای کامل (UI / Service / Model / Repository / Security)
- 🔑 چهار نقش کاربری با کنترل دسترسی مجزا (SuperAdmin, HotelManager, Receptionist, Guest)
- 🛏️ مدیریت کامل اتاق‌ها با ۴ نوع مختلف و فرمول قیمت‌گذاری فصلی
- 📅 چرخه‌ی کامل رزرو (جستجو → رزرو → Check-In → Check-Out) با الگوی Observer برای لیست انتظار
- 💳 سیستم مالی کامل: فاکتور دقیق، پرداخت قسطی، جلوگیری از خروج با بدهی معوق
- ⭐ ارتقای خودکار سطح عضویت (BRONZE → SILVER → GOLD → PLATINUM)
- 🧹 ۵ نوع خدمات جانبی (مینی‌بار، نظافت، پارکینگ، تعمیرات، سرویس اتاق)
- 📊 ۶ گزارش مدیریتی کامل
- 📝 لاگ‌گیری امنیتی استاندارد برای تمام رویدادهای حساس
- 💾 ذخیره‌سازی و بازیابی کامل داده روی فایل (بدون نیاز به دیتابیس)
- ✅ مجموعه تست خودکار با ۷۹ بررسی مستقل (بدون هیچ کتابخانه‌ی تست خارجی)

## 🖥️ پیش‌نمایش

```
╔═══════════════════════════════════════════════════════════╗
║ HOTEL GRAND PERSIA - Management System                    ║
╠═══════════════════════════════════════════════════════════╣
║ Logged in as: RECEPTIONIST | User: alireza                ║
╠═══════════════════════════════════════════════════════════╣
║ 1. Search Available Rooms                                 ║
║ 2. New Reservation                                        ║
║ 3. Check-In                                               ║
║ 4. Check-Out                                              ║
║ 5. Guest Services                                         ║
║ 6. Guest History (Report R-06)                            ║
║ 0. Logout                                                 ║
╚═══════════════════════════════════════════════════════════╝
Select option: _
```

## 🚀 شروع سریع

### پیش‌نیاز

- JDK نسخه‌ی ۱۱ یا بالاتر

### اجرا از سورس

**گزینه‌ی ۱ — دانلود مستقیم فقط همین پوشه (ساده‌ترین راه):**

به [این لینک](https://download-directory.github.io/?url=https://github.com/alireza-zarebidoki/University-codes/tree/main/S-2/Advanced-Programming/Project/GrandPersiaHMS) برو تا یک فایل ZIP فقط از پوشه‌ی همین پروژه دانلود شود، سپس آن را از حالت فشرده خارج کن.

**گزینه‌ی ۲ — کلون کل مخزن:**

```bash
git clone https://github.com/alireza-zarebidoki/University-codes.git
cd University-codes/S-2/Advanced-Programming/Project/GrandPersiaHMS
```

**کامپایل و اجرا (مشترک بین هر دو گزینه):**

```bash
javac -d out $(find src -name "*.java")
java -cp out com.grandpersia.Main
```

در اولین اجرا، حساب مدیر ارشد به‌صورت خودکار ساخته می‌شود:

```
username: admin
password: admin123
```

### ساخت و اجرای فایل JAR

```bash
echo "Main-Class: com.grandpersia.Main" > manifest.txt
jar cfm hotel-management.jar manifest.txt -C out .
java -jar hotel-management.jar
```

### اجرای تست خودکار

```bash
java -cp out com.grandpersia.SelfTest
```

۷۹ بررسی مستقل روی تمام ماژول‌های سیستم اجرا می‌شود و در چند ثانیه نتیجه‌ی کامل چاپ می‌شود:

```
==================================================
 TEST SUMMARY: 79 passed, 0 failed (out of 79 checks)
==================================================
 ALL CHECKS PASSED.
```

## 📁 ساختار پروژه

```
src/com/grandpersia/
├── Main.java                  نقطه‌ی ورود برنامه
├── SelfTest.java              مجموعه تست خودکار
├── model/                     کلاس‌های داده (کاربران، اتاق‌ها، رزرو، مالی، Enum ها)
├── interfaces/                Billable, Searchable<T>, Notifiable, Exportable
├── exception/                 ۷ Exception سفارشی
├── service/                   منطق تجاری (رزرو، عضویت، مالی، اتاق، گزارش)
├── security/                  احراز هویت، کنترل دسترسی، لاگ
├── repository/                نگه‌داری داده در حافظه + ذخیره‌سازی فایل
├── ui/                        رابط کاربری کنسولی و منوهای هر نقش
└── util/                      ابزارهای کمکی
```

## 📚 مستندات

| فایل | محتوا |
|---|---|
| [`DOCUMENTATION.md`](./DOCUMENTATION.md) | توضیح کامل معماری، تمام کلاس‌ها و فیلدها، الگوهای طراحی |
| [`DOCUMENTATION.pdf`](./DOCUMENTATION.pdf) / [`DOCUMENTATION.tex`](./DOCUMENTATION.tex) | نسخه‌ی رسمی و صفحه‌بندی‌شده‌ی همان مستندات (LaTeX) |
| [`TESTING.md`](./TESTING.md) | راهنمای کامل تست خودکار و دستی |

## 🛠️ فناوری‌ها

- **زبان:** Java (بدون هیچ فریمورک یا کتابخانه‌ی خارجی)
- **رابط کاربری:** کنسول (`Scanner` / `System.out`)
- **ذخیره‌سازی:** `java.io.Serializable` (فایل باینری، بدون دیتابیس)
- **تست:** کلاس تست خودکار سفارشی (بدون JUnit)

## 📄 یادداشت

این پروژه به‌عنوان پروژه‌ی پایان‌ترم درس برنامه‌سازی پیشرفته دانشکده علوم ریاضی دانشگاه فردوسی مشهد توسعه داده شده است.

# مستندات پروژه — سیستم مدیریت هتل گرند پرشیا (Hotel Grand Persia Management System)

این سند مطابق با الزام بخش تحویلی‌های صورت پروژه («فایل داکیومنت با دستور اجرا و توضیح تمام فیلدها و کلاس‌های پیاده‌شده») تهیه شده و شامل دو بخش اصلی است: نحوه‌ی اجرای پروژه، و توضیح کامل معماری، کلاس‌ها و فیلدهای پیاده‌سازی‌شده.

## فهرست مطالب

- [۱. معرفی پروژه](#۱-معرفی-پروژه)
- [۲. نحوه‌ی اجرا](#۲-نحوه‌ی-اجرا)
- [۳. ساختار پوشه‌ها](#۳-ساختار-پوشه‌ها)
- [۴. معماری کلی](#۴-معماری-کلی)
- [۵. توضیح کامل Enum ها](#۵-توضیح-کامل-enum-ها)
- [۶. توضیح کامل اینترفیس‌ها](#۶-توضیح-کامل-اینترفیس‌ها)
- [۷. توضیح کامل Exception های سفارشی](#۷-توضیح-کامل-exception-های-سفارشی)
- [۸. توضیح کامل مدل‌های داده (کاربران)](#۸-توضیح-کامل-مدل‌های-داده-کاربران)
- [۹. توضیح کامل مدل‌های داده (اتاق‌ها)](#۹-توضیح-کامل-مدل‌های-داده-اتاق‌ها)
- [۱۰. توضیح کامل مدل‌های داده (رزرو و مالی)](#۱۰-توضیح-کامل-مدل‌های-داده-رزرو-و-مالی)
- [۱۱. لایه‌ی سرویس‌ها](#۱۱-لایه‌ی-سرویس‌ها)
- [۱۲. لایه‌ی امنیت](#۱۲-لایه‌ی-امنیت)
- [۱۳. لایه‌ی Repository و ذخیره‌سازی فایل](#۱۳-لایه‌ی-repository-و-ذخیره‌سازی-فایل)
- [۱۴. لایه‌ی رابط کاربری (کنسول)](#۱۴-لایه‌ی-رابط-کاربری-کنسول)
- [۱۵. کلاس‌های کمکی (Util)](#۱۵-کلاس‌های-کمکی-util)
- [۱۶. نقطه‌ی ورود و تست خودکار](#۱۶-نقطه‌ی-ورود-و-تست-خودکار)
- [۱۷. الگوهای طراحی به‌کاررفته](#۱۷-الگوهای-طراحی-به‌کاررفته)
- [۱۸. جدول تطبیق با الزامات صورت پروژه](#۱۸-جدول-تطبیق-با-الزامات-صورت-پروژه)

---

## ۱. معرفی پروژه

این پروژه یک سیستم شبیه‌سازی‌شده‌ی مدیریت هتل («هتل گرند پرشیا») است که به‌صورت کاملاً OOP و بدون استفاده از هیچ فریمورک یا کتابخانه‌ی خارجی (به‌جز خود JDK) در Java پیاده‌سازی شده است. سیستم به‌صورت کنسولی (Scanner/System.out) کار می‌کند، چهار نقش کاربری مجزا با سطوح دسترسی متفاوت دارد، و تمام قوانین تجاری مشخص‌شده در صورت پروژه (قیمت‌گذاری، چرخه‌ی رزرو، جریمه‌ی لغو، عضویت، فاکتور، خدمات جانبی، گزارش‌گیری، لاگ و امنیت) را پیاده می‌کند.

علاوه بر سه نمره‌ی اصلی، امتیاز اضافه‌ی «ذخیره‌سازی در فایل» نیز به‌صورت کامل پیاده‌سازی شده است.

---

## ۲. نحوه‌ی اجرا

### پیش‌نیاز

- JDK نسخه‌ی ۱۱ یا بالاتر

### کامپایل

دستورهای زیر باید از **ریشه‌ی پروژه** (پوشه‌ای که مستقیماً حاوی پوشه‌ی `src` است) اجرا شوند:

```bash
javac -d out $(find src -name "*.java")
```

### اجرای برنامه‌ی اصلی

```bash
java -cp out com.grandpersia.Main
```

در اولین اجرا، پیام زیر نمایش داده می‌شود و حساب مدیر ارشد به‌صورت خودکار ساخته می‌شود:

```
SuperAdmin account created (username: admin | password: admin123)
```

در اجراهای بعدی (اگر فایل `hotel_data.ser` از اجرای قبلی وجود داشته باشد)، به‌جای بوت‌استرپ مجدد، پیام زیر نمایش داده می‌شود و تمام داده‌های قبلی (اتاق‌ها، کاربران، رزروها، فاکتورها و ...) بازیابی می‌شوند:

```
Previous data loaded from 'hotel_data.ser'. Continuing where you left off.
```

### اجرای تست خودکار

```bash
java -cp out com.grandpersia.SelfTest
```

این دستور ۷۹ بررسی خودکار روی تمام ماژول‌های سیستم (بدون نیاز به ورودی دستی) اجرا می‌کند و در انتها خلاصه‌ی نتایج را چاپ می‌کند. جزئیات کامل نحوه‌ی تست (خودکار و دستی) در فایل جداگانه‌ی `TESTING.md` آمده است.

### ساخت و اجرای فایل JAR

برای بسته‌بندی پروژه در یک فایل اجرایی `.jar` (بعد از کامپایل طبق بخش قبل):

```bash
# ساخت فایل manifest که کلاس اصلی (Main-Class) را مشخص می‌کند
echo "Main-Class: com.grandpersia.Main" > manifest.txt

# بسته‌بندی همه‌ی کلاس‌های کامپایل‌شده در یک jar
jar cfm hotel-management.jar manifest.txt -C out .

# اجرای برنامه از طریق jar
java -jar hotel-management.jar
```

اجرای مجموعه تست خودکار مستقیماً از همان jar (بدون نیاز به کامپایل مجدد):

```bash
java -cp hotel-management.jar com.grandpersia.SelfTest
```

### داده‌ی پیش‌فرض هتل

در اولین اجرا، ۵۰ اتاق به‌صورت خودکار ساخته می‌شوند:

| نوع اتاق | شماره‌ها | قیمت پایه | ظرفیت |
|---|---|---|---|
| STANDARD | 101–120 | 3,000,000 ریال | 2 نفر |
| DELUXE | 201–215 | 4,500,000 ریال | 3 نفر |
| SUITE | 301–310 | 6,000,000 ریال | 4 نفر |
| PENTHOUSE | 501–505 | 10,000,000 ریال | 6 نفر |

---

## ۳. ساختار پوشه‌ها

```
src/com/grandpersia/
│
├── Main.java                          نقطه‌ی ورود برنامه
├── SelfTest.java                      مجموعه تست خودکار (۷۹ بررسی)
│
├── model/
│   ├── enums/                         ۸ Enum (۶ اجباری + ۲ کمکی)
│   ├── person/                        Person, User, Guest
│   │   └── staff/                     Staff, Receptionist, HotelManager, SuperAdmin
│   ├── room/                          Room و ۴ زیرکلاس
│   ├── reservation/                   Reservation, ServiceOrder, MaintenanceRequest
│   └── billing/                       Invoice, Payment
│
├── interfaces/                        Billable, Searchable<T>, Notifiable, RoomObserver, Exportable
├── exception/                         ۸ کلاس Exception (۷ اجباری + ۱ پایه‌ی کمکی)
│
├── service/
│   ├── reservation/                   ReservationEngine, WaitlistManager, CancellationResult
│   ├── guest/                         MembershipService, MembershipUpgradeResult
│   ├── billing/                       BillingService, GuestServiceManager
│   ├── room/                          RoomService
│   └── report/                        Report, ReportService
│
├── security/                          ActivityLogger, LogLevel, AccessControl, AuthService
├── repository/                        ۴ Repository + SystemStateSnapshot + FilePersistenceManager
│
├── ui/
│   ├── ConsoleUI.java, ServiceContext.java
│   └── menu/                          SuperAdminMenu, HotelManagerMenu, ReceptionistMenu, GuestMenu
│
└── util/                              ConsoleFormatter, ConsoleInputHelper, DateUtils, IdGenerator
```

---

## ۴. معماری کلی

سیستم به‌صورت لایه‌ای طراحی شده است:

1. **لایه‌ی UI** (`ui`, `ui.menu`) — فقط رفت‌وآمد بین صفحات و خواندن ورودی؛ هیچ منطق تجاری ندارد.
2. **لایه‌ی سرویس** (`service.*`) — تمام منطق تجاری (چرخه‌ی رزرو، محاسبه‌ی فاکتور، ارتقای عضویت، گزارش‌گیری) این‌جاست.
3. **لایه‌ی مدل** (`model.*`) — کلاس‌های داده؛ هرکدام فقط دانشی درباره‌ی خودشان دارند (مثلاً `Room` فرمول قیمت خودش را می‌داند، اما از قوانین رزرو چیزی نمی‌داند).
4. **لایه‌ی Repository** (`repository`) — نگه‌داری مجموعه‌های سراسری (همه‌ی اتاق‌ها، همه‌ی کاربران و ...) در حافظه، به‌علاوه‌ی ذخیره‌سازی روی فایل.
5. **لایه‌ی امنیت** (`security`) — احراز هویت، کنترل دسترسی، لاگ.

قاعده‌ی طراحی کلیدی: تنها `ReservationEngine` مجاز است وضعیت یک `Reservation` یا `Room` را تغییر دهد؛ این تمرکز از دور زدن قوانین تجاری (مثل جریمه‌ی لغو) توسط بخش‌های دیگر جلوگیری می‌کند.

---

## ۵. توضیح کامل Enum ها

تمام Enum ها در پکیج `model.enums` قرار دارند.

### `RoomType`
مقادیر: `STANDARD`, `DELUXE`, `SUITE`, `PENTHOUSE`

### `RoomStatus`
مقادیر: `AVAILABLE`, `RESERVED`, `OCCUPIED`, `MAINTENANCE`, `OUT_OF_SERVICE`

### `ReservationStatus`
مقادیر: `PENDING`, `CONFIRMED`, `ACTIVE`, `COMPLETED`, `CANCELLED`

### `MembershipLevel`
| مقدار | فیلد `discountRate` | فیلد `perkDescription` |
|---|---|---|
| BRONZE | 0.0 | No special perk |
| SILVER | 0.05 | 5% discount on stays |
| GOLD | 0.10 | 10% discount + free parking |
| PLATINUM | 0.15 | 15% discount + upgrade to the best available room |

متد `isLowerThan(MembershipLevel other)`: بر اساس ترتیب تعریف enum (`ordinal()`) مشخص می‌کند آیا سطح فعلی پایین‌تر از سطح داده‌شده است — مبنای تشخیص «آیا واقعاً ارتقا رخ داده».

### `UserRole`
مقادیر: `SUPER_ADMIN`, `HOTEL_MANAGER`, `RECEPTIONIST`, `GUEST`

### `Season`
| مقدار | فیلد `multiplier` |
|---|---|
| PEAK | 1.5 |
| NORMAL | 1.2 |
| OFF | 0.8 |

### `ShiftType` (کمکی)
مقادیر: `MORNING`, `EVENING`, `NIGHT` — فیلد `shiftType` کلاس `Receptionist`.

### `MaintenanceStatus` (کمکی)
مقادیر: `PENDING`, `APPROVED`, `REJECTED` — وضعیت گردش کار درخواست‌های تعمیرات.

---

## ۶. توضیح کامل اینترفیس‌ها

تمام اینترفیس‌ها در پکیج `interfaces` قرار دارند.

### `Billable`
| متد | توضیح |
|---|---|
| `double calculateTotal()` | مبلغ کل قبل از تخفیف اضافه |
| `double applyDiscount(double percentage)` | اعمال یک تخفیف اضافی (غیر از تخفیف عضویت) روی مبلغ کل |

پیاده‌سازی‌کنندگان: `Reservation`, `Invoice`

### `Searchable<T>` (اینترفیس Generic پروژه)
| متد | توضیح |
|---|---|
| `List<T> search(String query)` | جستجوی متنی ساده |
| `List<T> filter(Predicate<T> predicate)` | فیلتر با شرط دلخواه |

پیاده‌سازی‌کنندگان:
- `Room implements Searchable<Reservation>` — جستجو در تاریخچه‌ی رزروهای همان اتاق
- `Guest implements Searchable<Reservation>` — جستجو در تاریخچه‌ی رزروهای همان مهمان
- `Reservation implements Searchable<ServiceOrder>` — جستجو در خدمات سفارش‌داده‌شده‌ی همان رزرو

### `Notifiable` (سمت Subject الگوی Observer)
| متد | توضیح |
|---|---|
| `void registerObserver(RoomObserver observer)` | ثبت یک ناظر |
| `void removeObserver(RoomObserver observer)` | حذف یک ناظر |
| `void notifyObservers(String roomNumber)` | اطلاع‌رسانی به همه‌ی ناظرها |

پیاده‌سازی‌کننده: `ReservationEngine`

### `RoomObserver` (سمت Observer الگوی Observer)
| متد | توضیح |
|---|---|
| `void onRoomAvailable(String roomNumber)` | فراخوانی خودکار هنگام آزاد شدن یک اتاق |

پیاده‌سازی‌کننده: `WaitlistManager`

### `Exportable`
| متد | توضیح |
|---|---|
| `String exportToText()` | خروجی متنی آماده‌ی چاپ (جدول ASCII) |

پیاده‌سازی‌کنندگان: `Invoice`, `Report`

---

## ۷. توضیح کامل Exception های سفارشی

همه در پکیج `exception`، همگی از `HotelException` (کلاس پایه‌ی کمکی، خودش از `Exception` ارث می‌برد) مشتق شده‌اند.

| کلاس | چه زمانی throw می‌شود | نمونه‌ی محل استفاده‌ی واقعی در کد |
|---|---|---|
| `RoomNotAvailableException` | تلاش برای رزرو اتاقی که در وضعیت AVAILABLE نیست | `ReservationEngine.createReservation` |
| `RoomNotFoundException` | جستجوی شماره اتاقی که وجود ندارد | `InMemoryRoomRepository.getByRoomNumber`, `RoomService` |
| `AccessDeniedException` | تلاش برای عملیات غیرمجاز بر اساس نقش، یا لاگین ناموفق | `AccessControl`, `AuthService.login` |
| `ReservationConflictException` | تداخل تاریخ با یک رزرو فعال دیگر روی همان اتاق | `ReservationEngine.createReservation` |
| `InsufficientPaymentException` | پیش‌پرداخت ناکافی، پرداخت نامعتبر، یا بدهی معوق هنگام Check-Out | `ReservationEngine.confirmPayment`, `Invoice.addPayment`, `BillingService.ensureNoOutstandingBalance` |
| `GuestNotFoundException` | جستجوی کد ملی‌ای که در سیستم ثبت نشده | `InMemoryGuestRepository.getByNationalId` |
| `InvalidDateRangeException` | تاریخ خروج قبل یا برابر تاریخ ورود | `ReservationEngine.createReservation` |

> `HotelException` عمداً کلاس پایه‌ی مشترک است، اما منطق تجاری هیچ‌جا بر پایه‌ی این نوع پایه تصمیم نمی‌گیرد — همیشه با نوع دقیق (`catch` اختصاصی) کار می‌شود. این کلاس فقط برای مدیریت خطای عمومی و لاگ سراسری کاربرد دارد.

---

## ۸. توضیح کامل مدل‌های داده (کاربران)

پکیج: `model.person` و `model.person.staff`

### `Person` (abstract)
| فیلد | نوع | توضیح |
|---|---|---|
| `username` | `String` | نام کاربری، غیرقابل‌تغییر |
| `fullName` | `String` | نام کامل |

متد abstract: `getDisplayInfo()` — هر زیرکلاس نمایش اختصاصی خودش را برمی‌گرداند.

### `User` (abstract, extends Person)
| فیلد | نوع | توضیح |
|---|---|---|
| `password` | `String` | رمز عبور |
| `role` | `UserRole` | نقش کاربر |
| `active` | `boolean` | فعال/غیرفعال بودن حساب |

متدهای کلیدی: `checkPassword(String)`, `changePassword(String)`, `setActive(boolean)`

### `Guest` (extends User, implements `Searchable<Reservation>`)
| فیلد | نوع | توضیح |
|---|---|---|
| `nationalId` | `String` | کد ملی، ۱۰ رقمی، کلید جستجو |
| `phone` | `String` | شماره تماس |
| `membershipLevel` | `MembershipLevel` | سطح عضویت فعلی |
| `totalStays` | `int` | تعداد کل اقامت‌ها |
| `reservationHistory` | `List<Reservation>` | تاریخچه‌ی رزروها |

### `Staff` (abstract, extends User)
| فیلد | نوع | توضیح |
|---|---|---|
| `employeeId` | `String` | کد پرسنلی |
| `hireDate` | `LocalDate` | تاریخ استخدام |

### `Receptionist` (extends Staff)
| فیلد | نوع | توضیح |
|---|---|---|
| `shiftType` | `ShiftType` | شیفت کاری (صبح/عصر/شب) |

### `HotelManager` (extends Staff)
| فیلد | نوع | توضیح |
|---|---|---|
| `departmentName` | `String` | نام بخش تحت مدیریت |

### `SuperAdmin` (extends Staff)
| فیلد | نوع | توضیح |
|---|---|---|
| `SYSTEM_CONFIG_ACCESS` | `boolean` (static final) | همیشه `true`، بدون setter |

---

## ۹. توضیح کامل مدل‌های داده (اتاق‌ها)

پکیج: `model.room`

### `Room` (abstract, implements `Searchable<Reservation>`)
| فیلد | نوع | توضیح |
|---|---|---|
| `roomNumber` | `String` | شماره اتاق |
| `type` | `RoomType` | نوع اتاق |
| `status` | `RoomStatus` | وضعیت فعلی |
| `basePrice` | `double` | قیمت پایه (قابل ویرایش توسط SuperAdmin) |
| `floorNumber` | `int` | شماره طبقه |
| `capacity` | `int` | حداکثر ظرفیت |
| `bookingHistory` | `List<Reservation>` | تاریخچه‌ی رزروهای این اتاق |

متد abstract: `getTypeMultiplier()` — هر زیرکلاس ضریب قیمت خودش را برمی‌گرداند.

متدهای کلیدی:
- `calculateGrossPrice(Season, int)` — قیمت هر شب **بدون** تخفیف عضویت (پایه‌ی محاسبه‌ی فاکتور رسمی)
- `calculatePrice(Season, int, MembershipLevel)` — قیمت هر شب **با** تخفیف عضویت (برای برآورد اولیه)
- `isAvailableFor(LocalDate, LocalDate)` — بررسی تداخل تاریخ با رزروهای فعال

### زیرکلاس‌ها و ضریب قیمت

| کلاس | ضریب قیمت |
|---|---|
| `StandardRoom` | 1.0 |
| `DeluxeRoom` | 1.5 |
| `Suite` | 2.5 |
| `PentHouse` | 5.0 |

---

## ۱۰. توضیح کامل مدل‌های داده (رزرو و مالی)

### `Reservation` (پکیج `model.reservation`, implements `Billable`, `Searchable<ServiceOrder>`)
| فیلد | نوع | توضیح |
|---|---|---|
| `reservationId` | `String` | کد یکتا (فرمت `R-00001`) |
| `guest` | `Guest` | مهمان صاحب رزرو |
| `room` | `Room` | اتاق رزروشده |
| `checkInDate` / `checkOutDate` | `LocalDate` | بازه‌ی اقامت |
| `guestCount` | `int` | تعداد مهمانان |
| `status` | `ReservationStatus` | وضعیت فعلی (فقط توسط `ReservationEngine` تغییر می‌کند) |
| `orderedServices` | `List<ServiceOrder>` | خدمات جانبی سفارش‌داده‌شده |

`calculateTotal()`: برآورد سریع (اقامت + خدمات، با تخفیف عضویت) — برای محاسبه‌ی حداقل پیش‌پرداخت؛ فاکتور رسمی توسط `Invoice` محاسبه می‌شود.

### `ServiceOrder`
| فیلد | نوع | توضیح |
|---|---|---|
| `serviceName` | `String` | نام خدمت |
| `price` | `double` | قیمت |
| `orderedAt` | `LocalDateTime` | زمان سفارش |

### `MaintenanceRequest`
| فیلد | نوع | توضیح |
|---|---|---|
| `room` | `Room` | اتاق موردنظر |
| `description` | `String` | شرح مشکل |
| `requestedAt` | `LocalDateTime` | زمان ثبت |
| `status` | `MaintenanceStatus` | PENDING/APPROVED/REJECTED |

### `Invoice` (پکیج `model.billing`, implements `Billable`, `Exportable`)
| فیلد | نوع | توضیح |
|---|---|---|
| `invoiceId` | `String` | کد یکتا (فرمت `INV-00001`) |
| `reservation` | `Reservation` | رزرو مرتبط |
| `payments` | `List<Payment>` | تراکنش‌های پرداخت‌شده |
| `finalized` | `boolean` | آیا فاکتور قفل شده یا هنوز زنده است |
| `frozen*` (۶ فیلد) | `double` | مقادیر منجمدشده‌ی فاکتور بعد از قفل شدن |

فرمول کامل (طبق ماژول ۴ سند): هزینه‌ی اقامت + هزینه‌ی خدمات − تخفیف عضویت (روی جمع دو مورد قبل) → مبلغ پس از تخفیف → + عوارض شهری (۱٪) + ارزش‌افزوده (۹٪) = جمع کل.

متد `finalizeInvoice()`: فاکتور را در لحظه‌ی Out-Check قفل می‌کند تا تغییرات بعدی سطح عضویت مهمان، مبلغ نهایی را عقب‌گرد و دوباره‌محاسبه نکند.

### `Payment`
| فیلد | نوع | توضیح |
|---|---|---|
| `amount` | `double` | مبلغ پرداختی |
| `paidAt` | `LocalDateTime` | زمان پرداخت (خودکار) |

---

## ۱۱. لایه‌ی سرویس‌ها

### `ReservationEngine` (پکیج `service.reservation`, implements `Notifiable`)
تنها کلاس مجاز به تغییر وضعیت `Reservation` یا `Room`.

| متد | توضیح |
|---|---|
| `createReservation(...)` | ساخت رزرو (PENDING)، قفل اتاق (RESERVED) |
| `confirmPayment(...)` | تایید پیش‌پرداخت (حداقل ۲۰٪) → CONFIRMED |
| `checkIn(...)` | → ACTIVE، اتاق OCCUPIED |
| `checkOut(...)` | → COMPLETED، اتاق AVAILABLE، اطلاع به Observer ها |
| `cancelReservation(...)` | محاسبه‌ی جریمه (۱۰۰٪/۵۰٪/۰٪ بر اساس فاصله تا ورود) → CANCELLED |

### `WaitlistManager` (implements `RoomObserver`)
فیلد: `waitlists` (`Map<String, Queue<Guest>>`) — صف انتظار به تفکیک شماره اتاق.

### `CancellationResult`
Value Object نتیجه‌ی لغو: `totalAmount`, `penaltyAmount`, `refundAmount`, `penaltyRate`.

### `MembershipService` (پکیج `service.guest`)
متد `processCheckOut(Guest)`: افزایش `totalStays` + بررسی خودکار ارتقا (آستانه‌ها: ۵→SILVER، ۱۵→GOLD، ۳۰→PLATINUM).

### `MembershipUpgradeResult`
Value Object: `upgraded`, `previousLevel`, `newLevel`, `message`، متد `requiresBestRoomUpgrade()`.

### `BillingService` (پکیج `service.billing`)
مدیریت مرکزی فاکتورها؛ متدهای کلیدی: `getOrCreateInvoice`, `registerPayment`, `canCheckOut`, `ensureNoOutstandingBalance`, `finalizeInvoice`.

### `GuestServiceManager`
پیاده‌سازی هر ۵ خدمت جانبی (مینی‌بار، نظافت فوری با کنترل ساعت کاری ۸-۲۰، پارکینگ اضافه با تخفیف GOLD+، درخواست تعمیرات با گردش کار تایید/رد، سرویس اتاق).

### `RoomService` (پکیج `service.room`)
جستجوی اتاق خالی بر اساس نوع/تاریخ، افزودن/حذف اتاق، تغییر وضعیت، تشخیص «بهترین اتاق موجود».

### `Report` و `ReportService` (پکیج `service.report`)
`Report implements Exportable`. `ReportService` هر ۶ گزارش سند را تولید می‌کند:

| کد | نام | مخاطب |
|---|---|---|
| R-01 | وضعیت لحظه‌ای اتاق‌ها | همه |
| R-02 | اشغال روزانه | Manager, SuperAdmin |
| R-03 | درآمد ماهانه | Manager, SuperAdmin |
| R-04 | محبوب‌ترین اتاق‌ها | Manager |
| R-05 | لیست بدهکاران | Manager, SuperAdmin |
| R-06 | تاریخچه مهمان | Receptionist, Manager |

---

## ۱۲. لایه‌ی امنیت

پکیج: `security`

### `ActivityLogger`
فرمت لاگ دقیقاً مطابق سند: `[timestamp] [LEVEL] [User: ...] [Action: ...] [کلید: مقدار] ...`

### `LogLevel`
مقادیر: `INFO`, `ERROR`

### `AccessControl`
متدها: `requireRole`, `requireAnyRole`, `requireActiveAccount` — همگی `AccessDeniedException` می‌اندازند.

### `AuthService`
| متد | توضیح |
|---|---|
| `bootstrapSuperAdmin()` | ساخت خودکار حساب `admin`/`admin123` |
| `registerGuest(...)` | ثبت‌نام آزاد مهمان |
| `createHotelManager(...)` | فقط توسط SuperAdmin |
| `createReceptionist(...)` | فقط توسط HotelManager |
| `login` / `logout` | با پیام خطای یکسان برای «کاربر نامعتبر» و «رمز اشتباه» (اصل امنیتی) |
| `deactivateAccount(...)` | فقط توسط SuperAdmin |

---

## ۱۳. لایه‌ی Repository و ذخیره‌سازی فایل

پکیج: `repository`

| کلاس | نگه‌داری | کلید |
|---|---|---|
| `InMemoryRoomRepository` | اتاق‌ها | شماره اتاق |
| `InMemoryUserRepository` | همه‌ی کاربران (برای لاگین) | نام کاربری |
| `InMemoryGuestRepository` | مهمانان | کد ملی |
| `InMemoryReservationRepository` | رزروها | کد رزرو |

### `SystemStateSnapshot`
عکس فوری (Serializable) از کل وضعیت سیستم: اتاق‌ها، کاربران، رزروها، فاکتورها، لیست‌های انتظار، درخواست‌های تعمیرات، لاگ‌ها، شمارنده‌ی کدهای رزرو/فاکتور.

### `FilePersistenceManager`
پیاده‌سازی امتیاز اضافه‌ی ذخیره‌سازی فایل، با `java.io.Serializable` و `ObjectOutputStream`/`ObjectInputStream` (بخشی از خود JDK، نه کتابخانه‌ی خارجی).

| متد | توضیح |
|---|---|
| `saveState(...)` | نوشتن یک `SystemStateSnapshot` واحد روی دیسک (حفظ هم‌ارجاعی گراف اشیاء) |
| `loadState(...)` | بازیابی و پخش داده بین Repository ها؛ `false` برمی‌گرداند اگر فایل وجود نداشته باشد |
| `getStorageInfo(...)` | اطلاعات خلاصه‌ی فایل (مسیر، حجم، آخرین ذخیره) برای نمایش در منوی SuperAdmin |

ذخیره‌سازی از طریق یک **Shutdown Hook** در `Main.java` انجام می‌شود، که هم خروج تمیز و هم قطع ناگهانی برنامه را پوشش می‌دهد.

---

## ۱۴. لایه‌ی رابط کاربری (کنسول)

پکیج: `ui`, `ui.menu`

### `ServiceContext`
ظرف نگه‌دارنده‌ی تمام سرویس‌ها/Repository ها؛ به هر منو پاس داده می‌شود تا از تکرار پارامتر جلوگیری شود.

### `ConsoleUI`
حلقه‌ی اصلی: صفحه‌ی ورود/ثبت‌نام → مسیریابی به منوی مخصوص نقش.

### منوها (`ui.menu`)
| کلاس | قابلیت‌های کلیدی |
|---|---|
| `SuperAdminMenu` | ساخت HotelManager، ویرایش قیمت پایه، گزارش‌های مالی، غیرفعال‌سازی حساب، مشاهده‌ی لاگ، **وضعیت ذخیره‌سازی فایل** |
| `HotelManagerMenu` | مدیریت اتاق، ساخت Receptionist، گزارش‌ها (R-01 تا R-04)، تایید/رد تعمیرات |
| `ReceptionistMenu` | جستجوی اتاق، رزرو جدید، Check-In/Out، خدمات جانبی، تاریخچه‌ی مهمان |
| `GuestMenu` | جستجو، رزرو مستقیم، مشاهده‌ی رزروها، لغو، تاریخچه، سطح عضویت |

---

## ۱۵. کلاس‌های کمکی (Util)

پکیج: `util`

| کلاس | مسئولیت |
|---|---|
| `ConsoleFormatter` | رسم جعبه‌های منو (سبک ╔══╗) |
| `ConsoleInputHelper` | خواندن ورودی معتبر (عدد، اعشار، تاریخ) با تلاش مجدد خودکار |
| `DateUtils` | تشخیص فصل از روی شماره‌ی ماه (تقویم شمسی) |
| `IdGenerator` | تولید کد یکتای رزرو/فاکتور؛ شمارنده‌ها برای ذخیره‌سازی فایل قابل export/import هستند |

---

## ۱۶. نقطه‌ی ورود و تست خودکار

### `Main.java`
بوت‌استرپ کامل: ساخت تمام Repository ها و سرویس‌ها، بارگذاری داده از فایل (یا ساخت ۵۰ اتاق اولیه)، ثبت Shutdown Hook، شروع `ConsoleUI`.

### `SelfTest.java`
مجموعه‌ی ۷۹ بررسی خودکار (بدون هیچ کتابخانه‌ی تست خارجی) روی تمام ماژول‌ها؛ جزئیات کامل در `TESTING.md`.

---

## ۱۷. الگوهای طراحی به‌کاررفته

| الگو | کجا استفاده شده | چرا |
|---|---|---|
| **Template Method** | `Room.calculatePrice()` | فرمول مشترک در والد، فقط ضریب نوع در فرزندان |
| **Observer** | `Notifiable` / `RoomObserver` / `ReservationEngine` / `WaitlistManager` | اطلاع‌رسانی خودکار آزادشدن اتاق به لیست انتظار |
| **Repository** | پکیج `repository` | جداسازی نگه‌داری داده از منطق تجاری |
| **Dependency Injection (دستی)** | `ServiceContext`, `AuthService`, `ReportService` | تزریق وابستگی‌ها به‌جای ساخت مستقیم داخل کلاس |
| **Value Object** | `CancellationResult`, `MembershipUpgradeResult`, `FileStorageInfo` | نتایج پیچیده به‌صورت یک شیء تغییرناپذیر برگردانده می‌شوند |
| **Snapshot / Memento (اقتباسی)** | `SystemStateSnapshot` | عکس فوری کامل از وضعیت سیستم برای ذخیره‌سازی فایل |

---

## ۱۸. جدول تطبیق با الزامات صورت پروژه

| الزام | وضعیت |
|---|---|
| ۷ ماژول اصلی سند | پیاده‌سازی و تست‌شده |
| هر ۶ Enum اجباری | پیاده‌سازی‌شده (+ ۲ Enum کمکی) |
| هر ۴ اینترفیس اجباری (`Billable`, `Searchable<T>`, `Notifiable`, `Exportable`) | پیاده‌سازی‌شده |
| حداقل یک Generic Class/Interface | `Searchable<T>` |
| هر ۷ Exception سفارشی | پیاده‌سازی و در کد واقعاً throw می‌شوند |
| بدون فریمورک/کتابخانه‌ی خارجی | رعایت‌شده (فقط JDK استاندارد) |
| تعامل کامل از طریق Scanner/System.out | رعایت‌شده |
| امتیاز اضافه: ذخیره‌سازی فایل (I/O) | پیاده‌سازی و تست‌شده |

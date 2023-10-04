## Unit Tests

### 1. The Three Laws of TDD
Unit tests come before production code.

**First Law:** You may not write production code until you have written a failing unit test.
**Second Law:** You may not write more of a unit test than is sufficient to fail, and not compiling is failing.
**Third Law:** You may not write more production code that is sufficient to pass the currently failing test.

### 2. Keeping Tests Clean
- `Readability:` Clarity, simplicity and density of expression.
- Reader should not be swarmed with irrevelant details in the test.

**Build-Operate-Check (BOC)/ Arrange-Act-Assert (AAA) Pattern:** Structures tests into three distinct stages.
1. **Build (or Arrange):** Set up the object or system you want to test. Ie. Create an instance.
2. **Operate (or Act):** Perform the action you want to test.
3. **Check (or Assert):** Check for expected result.

### 3. A Dual Standard
Bouncing between True/False and the condition makes it less readable:
*In Java:*
```java
@Test
 public void turnOnLoTempAlarmAtThreashold() throws Exception {
 hw.setTemp(WAY_TOO_COLD);
 controller.tic();
 assertTrue(hw.heaterState());
 assertTrue(hw.blowerState());
 assertFalse(hw.coolerState());
 assertFalse(hw.hiTempAlarm());
 assertTrue(hw.loTempAlarm());
 }
```
Which can be refactored to:
```java
@Test
 public void turnOnLoTempAlarmAtThreshold() throws Exception {
 wayTooCold();
 assertEquals("HBchL", hw.getState());
 }
```

### 4. One Assert per Test
- `TEMPLATE METHOD pattern`: Ie. HotBeverage class with a prepareRecipe method. Outlines method, but details are left to`subclasses`.

### 5. F.I.R.S.T
**Fast:** Tests should be fast.
**Independent:** Tests should not depend on each other.
**Repeatable:** Tests should be repeatable in any environment.
**Self-Validating:** Should have a boolean output, pass or fail.
**Timely:** The tests need to be written in a timely fashion, before production code.
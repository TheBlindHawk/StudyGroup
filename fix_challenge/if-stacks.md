```javascript
const getMoveSpeed = () => {
    if (canMove) {
        if(isMoving && !isOnWall) {
            if(isGrounded) {
                if(isRunning){
                    return runSpeed;
                } else {
                    return walkSpeed;
                }
            } else {
                return airWalkSpeed;
            }
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}
```

まずは```return 0```が二回呼ばれてるとこをまとめます。
同じ```return```を２回呼ぶ必要はなく、```return 0```は「動けない時」に返すものなので一番最初の一行目でスキップした方がいい。

```javascript
const getMoveSpeed = () => {
    if(!isMoving || !canMove || isOnWall) return 0;

    if(isGrounded) {
        if(isRunning){
            return runSpeed;
        } else {
            return walkSpeed;
        }
    } else {
        return airWalkSpeed;
    }
}
```

これがおそらく一番読みやすい書き方と思うけど、コードがもっと長かった場合```isGrounded```も最初に```return```させることができます。
一つ気をつけた方がいいのは最後に```return```がないことです。

```javascript
const getMoveSpeed = () => {
    if(!isMoving || !canMove || isOnWall) return 0;
    if(!isGrounded) return airWalkSpeed;

    if(isRunning){
        return runSpeed;
    } else {
        return walkSpeed;
    }
}
```

さらに```isRunning```もスキップします。

```javascript
const getMoveSpeed = () => {
    if(!isMoving || !canMove || isOnWall) return 0;
    if(!isGrounded) return airWalkSpeed;
    if(isRunning) return runSpeed;

    return walkSpeed;
}
```

**?:**を使う場合最後の部分を一行にまとめられます。

```javascript
const getMoveSpeed = () => {
    if(!isMoving || !canMove || isOnWall) return 0;
    return isGrounded ? isRunning ? runSpeed : walkSpeed : airWalkSpeed;
}
```
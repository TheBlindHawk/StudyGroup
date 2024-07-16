const canMove = false, isMoving = false, isRunning = false, isOnWall = false, isGrounded = false, runSpeed = 0, walkSpeed = 0, airWalkSpeed = 0;

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


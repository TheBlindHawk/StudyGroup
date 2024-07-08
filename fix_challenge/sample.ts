// this is the structure of the data you are given

type Users = {
  id: number
  name: string
  city: string
  dayOfBirth: Date
}[]

type Output = { name: string; birthday: Date }

const myData = {
  id: 12345,
  name: 'John Doe',
  city: 'New York',
  dayOfBirth: new Date('1990-01-01'),
}

// improve the code from here onwards

const getBirthdays = async (month: number, users: Users) => {
  const output: Output[] = []

  if (myData.id && myData.dayOfBirth && myData.city) {
    users = users.sort((a, b) => {
      const dateA = new Date(2000, a.dayOfBirth.getMonth(), a.dayOfBirth.getDate())
      const dateB = new Date(2000, b.dayOfBirth.getMonth(), b.dayOfBirth.getDate())
      return dateA.getTime() - dateB.getTime()
    })

    const myUsers = users.filter(
      (user) => {
        if (user.dayOfBirth === undefined || user.dayOfBirth > new Date()) {
          const userMonth = user.dayOfBirth.getMonth()
          if (userMonth === month) {
            if (user.city === myData.city) {
              return true
            } else {
              return false
            }
          }
          return false
        } else {
          console.error('User is missing data or birthdates are in the future')
          return false
        }
      },
    )

    users.filter((user) => user.id !== myData.id)

    myUsers.forEach((user) => {
      output.push({ name: user.name, birthday: user.dayOfBirth })
    })
  } else {
    throw new Error('User is missing data')
    return [];
  }

  if (myData.dayOfBirth > new Date()) {
    throw new Error('The users birthday is invalid')
    return [];
  } else {
    return output
  }
}

import { Injectable } from '@angular/core';

@Injectable({
  providedIn: 'root'
})
export class UserService {

  users : any[] = [];
  loggedInUser : any = null;

  constructor() { }

  register(user : any) {
    this.users.push(user);
  }

  login(email : string, password : string) {
    const user = this.users.find(user => user.email === email && user.password === password);
    if (user) {
      this.loggedInUser = user;
    }

    return !!user;
  }

  logout() {
    this.loggedInUser = null;
  }

  getLoggedInUser() {
    return this.loggedInUser;
  }
}

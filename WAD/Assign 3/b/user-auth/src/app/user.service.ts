import { Injectable } from '@angular/core';
import axios from 'axios';

@Injectable({
  providedIn: 'root'
})
export class UserService {

  loggedInUser : any = null;

  constructor() { }

  async register(user : any) {

    try {
      const res = await axios.post('http://localhost:3000/register', user);

      console.log(res);
      if (res.status === 200) {
        return true;
      } else {
        return false;
      }
    } catch (error) {
      console.error("Error registering user:", error);
      return false;
    }
  }

  async login(email : string, password : string) {
    const res = await axios.post('http://localhost:3000/login', { email, password });
    console.log(res);
    if (res.status === 200) {
      this.loggedInUser = res.data;
      console.log(this.loggedInUser);
      return true;
    } else {
      return false;
    }
  }

  logout() {
    this.loggedInUser = null;
  }

  getLoggedInUser() {
    return this.loggedInUser;
  }

  async update(user : any) {

    console.log(user.user);
    const res = await axios.put('http://localhost:3000/update', user.user);

    if (res.status === 200) {
      this.loggedInUser = res.data;
      console.log(this.loggedInUser);

      return true;
    }
    else{
      console.log("Error updating user");

      return false;
    }
  }

  async delete(user : any){
    console.log(user.user.email);

    const res = await axios.delete('http://localhost:3000/delete/' ,  {data : { "email" : user.user.email}});
    if (res.status === 200) {
      this.loggedInUser = null;
      console.log(this.loggedInUser);
      return true;
    }
    else{
      console.log("Error deleting user");
      return false;
    }
  }
}

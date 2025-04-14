import { Component , OnInit} from '@angular/core';
import { UserService } from '../user.service';
import { CommonModule } from '@angular/common';
import { FormsModule } from '@angular/forms';

@Component({
  selector: 'app-profile',
  standalone: true,
  imports: [FormsModule , CommonModule],
  templateUrl: './profile.component.html',
  styleUrl: './profile.component.css'
})
export class ProfileComponent implements OnInit{

  user: any = null;

  constructor(private userService: UserService) {}

  ngOnInit() {
    this.user = this.userService.getLoggedInUser();
    console.log("this.user : " , this.user);
    console.log(this.user.user.name);
  }

  logout() {
    location.href = '/';
    this.userService.logout();
  }

  async update() {
    const res= await this.userService.update(this.user);

    if(res === true){
      console.log("User updated");
      alert("User updated");
    }else {
      console.log("Error updating user");
      alert("Error updating user");
    }
  }

  async delete() {
    const res = await this.userService.delete(this.user);

    if(res === true){
      console.log("User deleted");
      alert("User deleted");
      location.href = '/';
    }else {
      console.log("Error deleting user");
      alert("Error deleting user");
    }
  }
}

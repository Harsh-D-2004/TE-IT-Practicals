import { Component } from '@angular/core';
import { Router } from '@angular/router';
import { UserService } from '../user.service';
import { FormsModule } from '@angular/forms';

@Component({
  selector: 'app-login',
  imports: [FormsModule],
  templateUrl: './login.component.html',
  styleUrl: './login.component.css'
})
export class LoginComponent {

  email = '';
  password = '';
  error = '';

  constructor(private userService: UserService, private router: Router) {}

  login() {
    const success : boolean = this.userService.login(this.email, this.password);
    if (success) {
      this.router.navigate(['/profile']);
    } else {
      this.error = 'Invalid credentials';
    }
  }

}

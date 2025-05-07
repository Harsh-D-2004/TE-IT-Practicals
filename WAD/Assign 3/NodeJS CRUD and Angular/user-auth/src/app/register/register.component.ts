import { Component } from '@angular/core';
import { UserService } from '../user.service';
import { Router } from '@angular/router';
import { FormsModule } from '@angular/forms';

@Component({
  selector: 'app-register',
  imports: [FormsModule],
  templateUrl: './register.component.html',
  styleUrl: './register.component.css'
})
export class RegisterComponent {

  user = { name: '', email: '', password: '' };

  constructor(private userService: UserService, private router: Router) {}

  async register() {
    const res = await this.userService.register(this.user);

    if(res === true) {
      this.router.navigate(['/login']);
    }
    else {
      alert('Error registering user');
    }
  }

}

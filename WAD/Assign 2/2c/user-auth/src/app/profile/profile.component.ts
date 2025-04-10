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
  }

}
